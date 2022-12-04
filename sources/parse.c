#include "../includes/cub3d.h"

void    startParse(t_all *all, char    *cub)
{
    int fd;

    checkFileName(cub);
    fd = open(cub, O_RDONLY);
    getTextures(all, fd);
    getMap(all, fd);
    setColors(all);
    close(fd);
    int i = 0;
    while (all->map.map[i])
    {
        printf("%s\n", all->map.map[i]);
        i++;
    }
}