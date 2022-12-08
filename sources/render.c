#include "../includes/cub3d.h"

void Drawdire(t_all *all, double x, double y)
{
    int d[2]; 
    int steps;
    float inc[2];
    float point[2];
    /* 0 for y, 1 for x*/
    d[0] = y -  all->player.px_y;
    d[1] = x -  all->player.px_x;
    if (ABS(d[1]) > ABS(d[0]))
        steps = ABS(d[1]);
    else
        steps = ABS(d[0]);
    inc[1] = d[1] / (float)steps;
    inc[0] = d[0] / (float)steps;
 
    point[0] = all->player.px_y;
    point[1] = all->player.px_x;
    while (steps)
       {

        pixel_to_image_put(&all->deps.calcs2, round(point[1]), round(point[0]),  0xFAFF5);
        point[1] += inc[1]; 
        point[0] += inc[0];
        steps--;
    }
}
void    drawmap(t_all *all)
{
    char    **map;
    int y;
    int x;

    x = 0;
    y = 0;
    map = all->map.map;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                drawSquaredRegion(&all->deps.calcs, y * bloc, x * bloc, 0xFACC5);
            x++;
        }
        y++;
    }
}

void    drawplayer(t_all *all, double x, double y)
{
    pixel_to_image_put(&all->deps.calcs, x, y,  0xFAFF5);
}
void    render(t_all *all)
{
    drawmap(all);
    drawplayer(all, all->player.px_x, all->player.px_y);
    copyImage(&all->deps.calcs2, &all->deps.calcs, all->map.x * bloc, all->map.y * bloc);
    Drawdire(all, all->player.px_x + cos(all->player.rad) * -20,  all->player.px_y + sin(all->player.rad)* -20);
    mlx_put_image_to_window(all->deps.mlx_ptr, all->deps.win_ptr[1], all->deps.calcs2.img, 0,0);
}

int hook(int keycode, t_all *data)
{
    if (keycode == Cleft)
        data->player.rad += 0.0804533 * (-1);
    if (keycode == Cright)
         data->player.rad += 0.0804533;
    if (keycode == Mup)
        horizontal(data, -1);
     if (keycode == Mdown)
        horizontal(data, 1);
    if (keycode == Mleft)
        vertical(data, 1);
    if (keycode == Mright)
        vertical(data, -1);
    mlx_clear_window(data->deps.mlx_ptr, data->deps.win_ptr[1]);
    render(data);
    return 0;
}