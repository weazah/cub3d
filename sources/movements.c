#include "../includes/cub3d.h"


void    horizontal(t_all *data, int where)
{

    data->player.px_y +=  (sin(data->player.rad) * where * 2);
    data->player.px_x +=  (cos(data->player.rad) * where * 2);

}

void    vertical(t_all *data, int where)
{

    data->player.px_y +=  sin(data->player.rad + (M_PI / 2)) * where * 2;
    data->player.px_x +=  cos(data->player.rad + (M_PI / 2)) * where * 2;

}