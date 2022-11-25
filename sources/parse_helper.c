#include "../includes/cub3d.h"

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

    return line;
}

void    d_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int parse_seq(char  *line)
{
    int len;

    len = ft_strlen (line);
    if (len == 1)
    {
        if (line[0] == 'F' || line[0] == 'C')
            return (0);
        return (1);
    }
    if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
        || !ft_strncmp(line, "WE", 2)|| !ft_strncmp(line, "EA", 2))
            return (0);
    return 1;
}

int    clac_seq(char   *line)
{
    return (line[0] + line[1]);
}

int     to_alocate(t_needs *needs, int code)
{
    int i;

    i = 0;
    if (code == clac_seq("NO") && !needs->images[0] && (i = 1))
        needs->images[0] = ft_calloc(1, sizeof(t_images));
    else if (code == clac_seq("SO") && !needs->images[1] && (i = 2))
        needs->images[1] = ft_calloc(1, sizeof(t_images)) ;
    else if (code == clac_seq("WE") && !needs->images[2] &&  (i = 3))
        needs->images[2] = ft_calloc(1, sizeof(t_images)) ;
    else if (code == clac_seq("EA") && !needs->images[3] && (i = 4))
        needs->images[3] = ft_calloc(1, sizeof(t_images)) ;
    else if ((code == clac_seq("F") || code == clac_seq("C")))
        return 0;
    if (i)
        return 0;
    return 1;
}