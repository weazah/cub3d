#include "../includes/cub3d.h"

void    drawsquare(t_needs *need, int y , int x)
{
    int xt;
    int yt;

    xt = x;
    yt = y;
    while(yt < y + H)
    {
        xt = x;
        while(xt < x + W)
        {
            mlx_pixel_put(need->mlx_ptr, need->win_ptr,xt, yt, 0xFFFFFF);
            xt++;
        }
        yt++;
    }
}
int    renderMap(int keycode, t_needs   *need)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (need->map[i])
    {
        j = 0;
        while (need->map[i][j])
        {
            if (need->map[i][j] == '1' && keycode)
                drawsquare(need, i * H , j * W);
            j++;
        }
        i++;
    }
    return 0;
}