#include "../includes/cub3d.h"

void    checkInput(t_all   *data)
{
    int count;

    count = 0;
    if (!data->player.dire)
        destruct(data, "Error no player");
    data->player.px_x = data->player.x * bloc;
    data->player.px_y = data->player.y * bloc;
    if (mapChecker(data->map.map))
        destruct(data, "Error\nthe map doesnt follow the rules\n");
    printf("%d %d %c\n", data->player.x, data->player.y,data->map.map[data->player.y][data->player.x]);
    data->map.map[data->player.y][data->player.x] = '0';
    printf("%d %d %c\n", data->player.x, data->player.y,data->map.map[data->player.y][data->player.x]);
}
void    startParse(t_all *all, char    *cub)
{
    int fd;

    checkFileName(cub);
    fd = open(cub, O_RDONLY);
    getTextures(all, fd);
    getMap(all, fd);
    setColors(all);
    checkInput(all);
    close(fd);    
}