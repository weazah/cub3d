#include "../includes/cub3d.h"

char    *skipNl(int fd)
{
    char    *line;

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            return NULL;
        if (line[0] != '\n' && notSpace(line))
            break ;
        free(line);
    }
    return (line);
}
void    checkFileName(char  *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4)
    {
        ft_putstr_fd("Error\nwrong file name\n", 2);
        exit(1);
    }
    if (ft_strncmp(file + len - 4, ".cub", 4))
    {
        ft_putstr_fd("Error\nwrong extention\n", 2);
        exit(1);
    }
}
void    toSlot(t_all *all, char *line, char *garbage)
{
    char    *tex[3];
    int i;
    
    free(garbage);
    i = 0;
    while (line[i] && line[i] != ' ')
        i++;
    if (i > 2)
        destruct(all, "Error\ntextures");
    tex[0] = ft_substr(line, 0, i);
    while (line[i] && line[i] == ' ')
        i++;
    tex[1] = ft_strdup(line +i);
    tex[2] = NULL;
    fitTex(all, tex);
}

void    getTextures(t_all *all, int fd)
{
    char    *line;
    int     i;

    i= 0;
    if (fd < 0)
    {
        ft_putstr_fd("Error\n{fd error}", 2);
        exit(1);
    }
    while (i < 6)
    {
        line = skipNl(fd);
        if (!line)
            destruct(all, "Error\nparsing colors and textures\n");
        toSlot(all, ft_strtrim(line, " \n"), line);
        i++;
    }

}
void    fitTex(t_all *all, char **tex)
{
    int code;

    code = getCode(tex[0]);
    if (code == -1)
        destruct(all, "Error\n textures");
    else if (code == 157 && !all->texs[0].file)
        all->texs[0].file = ft_strdup(tex[1]);
    else if (code == 162 && !all->texs[1].file)
        all->texs[1].file = ft_strdup(tex[1]);
    else if (code == 134 && !all->texs[2].file)
        all->texs[2].file = ft_strdup(tex[1]);
    else if (code == 156 && !all->texs[3].file)
        all->texs[3].file = ft_strdup(tex[1]);
    else if (code == 70 && !all->colors.sfloor)
        all->colors.sfloor = ft_strdup(tex[1]);
    else if (code == 67 && !all->colors.sceiling)
        all->colors.sceiling = ft_strdup(tex[1]);
    else
        destruct(all, "error\nduplicated parameter\n");
}

int getCode(char    *line)
{
    if (!ft_strncmp(line, "NO", 2))
        return ('N' + 'O');
    if (!ft_strncmp(line, "SO", 2))
        return ('S' + 'O');
    if (!ft_strncmp(line, "EA", 2))
        return ('E' + 'A');
    if (!ft_strncmp(line, "WE", 2))
        return ('W' + 'E');
    if (!ft_strncmp(line, "F", 2))
        return ('F');
    if (!ft_strncmp(line, "C", 2))
        return ('C');
    return (-1);
}
int notSpace(char   *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] == '\n')
            return 0;
        if (line[i] != ' ')
            return (1);
        i++;
    }
    return 0;
}