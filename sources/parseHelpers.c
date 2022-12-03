#include "../includes/cub3d.h"

static char    *skipNl(int fd)
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
    char    **tex;
    free(garbage);
    if (!line)
        destruct(all, "Error\nparsing colors and textures\n");
    tex = ft_split(line, " ");
    free(line);
    if (!tex)
        destruct(all, "Error\nparsing colors and textures\n");
    if ( !tex[1] || tex[2])
        {
            destruct(all, "Error\nparsing colors and textures\n")
            d_free(tex);
        }
    fitTex(all, tex);
    d_free(tex);
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