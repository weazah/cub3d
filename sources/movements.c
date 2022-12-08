#include "../includes/cub3d.h"


void    horizontal(t_all *data, int where)
{
    int x;
    int y;

    x = data->player.px_x;
    y = data->player.px_y;
    y = y + sin(data->player.rad) * where * 2;
    x = x + cos(data->player.rad) * where * 2;
    data->player.px_x = x;
    data->player.px_y = y;
}

void    vertical(t_all *data, int where)
{
    int x;
    int y;

    x = data->player.px_x;
    y = data->player.px_y;
    y = y + sin(data->player.rad - setRad(90)) * where * 2;
    x = x + cos(data->player.rad - setRad(90)) * where * 2;
    data->player.px_x = x;
    data->player.px_y = y;
}