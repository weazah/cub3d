#include "../includes/cub3d.h"

void    startParse(t_all *all, char    *cub)
{
    int fd;

    checkFileName(cub);
    fd = open(cub, O_RDONLY);
    getTextures(all, fd);

}