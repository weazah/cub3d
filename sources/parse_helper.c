#include "../includes/cub3d.h"

char    *skipNl(int fd)
{
    char    *line;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            return NULL;
        if (line[0] != '\n')
            break ;
        free(line);
    }
    return line;
}