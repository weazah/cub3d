#include "../includes/cub3d.h"

void    backGround(t_needs *need)
{
    int mid;
    int i;
    int j;

    mid = resy / 2;
    i = 0;
    j = 0;
    while (i < resy)
    {
        j = 0;
        while(j < resx)
        {
            if (i <= mid)
                mlx_pixel_put(need->mlx_ptr, need->win_ptr, j, i, need->c);
            else
                mlx_pixel_put(need->mlx_ptr, need->win_ptr, j, i, need->f);
            j++;
        }
        i++;
    }
}
void    updatePos(t_needs *need)
{
    int i = 0;
    int j = 0;
    int new_i = need->parser.posy / H;
    int new_j = need->parser.posx / W;
    while (need->map[i])
        {
            j = 0;
            while (need->map[i][j])
            {
                if (need->map[i][j] == 'P' || passable(need->map[i][j]))
                {
                    need->map[i][j] = '0';
                    need->map[new_i][new_j] = 'P';
                }
                j++;
            }

            i++;
        }
}
void    colorArea(t_needs *need)
{
    int x;
    int j;
    int i;

    i = 0;
    x = FRAMEW * W;
    j = resy - (FRAMEH * H);
    while (j < resy)
    {
        i = 0;
        while (i < x)
        {
            mlx_pixel_put(need->mlx_ptr, need->win_ptr, i, j, 3029810);
            i++;
        }
        j++;
    }
    

}
void    drawPlayer(t_needs   *need, int i, int j)
{
    int x; 
    int y; 

    x = need->parser.posx - j;
    y = need->parser.posy + (resy - (FRAMEH * H)) - i;
    while (y < (need->parser.posy + (resy - (FRAMEH * H)) + 5 - i))
    {
        x = need->parser.posx - j;
        while(x < (need->parser.posx + 5 - j))
        {
            mlx_pixel_put(need->mlx_ptr, need->win_ptr, x , y, 657930);
            x++;
        }
        y++;
    }

}

void    miniMap(t_needs *need, int y, int x)
{
    int j;

    j = x;
    colorArea(need);
    drawPlayer(need, y * H , x * W);
    // while(need->map[y])
    // {
    //     j = 0;
    //     while(need->map[y][j])
    //     {
    //         if (need->map[y][j] == 'P' || passable(need->map[y][j]))
                
    //         j++;
    //     }
    //     x++;
    // }
}
int getxindex(char  **map, int x, int total)
{
    int mid;
    int save;

    mid = FRAMEW / 2;
    if (mid > x)
        return 0;
    if ((total - x) < mid)
        return (total - FRAMEW);
    return (x - mid);
}
int getyindex(char  **map, int y, int total)
{
    int mid;
    int save;

    mid = FRAMEH / 2;
    if (mid > y)
        return 0;
    if ((total - y) < mid)
        return (total - FRAMEH);
    return (y - mid);
}
void    confMinimap(t_needs *needs, int *y, int *x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (needs->parser.mapx < FRAMEW)
        *x = 0;
     if (needs->parser.mapy < FRAMEH)
        *y = 0;
    if (*x == -1)
        *x = getxindex(needs->map, needs->parser.posx / W, needs->parser.mapx);
    if (*y == -1)
        *y = getyindex(needs->map, needs->parser.posy / H, needs->parser.mapy);
}
int    renderMap(int keycode, t_needs   *need)
{
    int i;
    int j;

    i = -1;
    j = -1;
    if (keycode == 1 && need->parser.posy < need->parser.mapy * H - 2)
        need->parser.posy+= 2;
    if (keycode == 13 && need->parser.posy)
        need->parser.posy-= 2;
    if (keycode == 2 && need->parser.posx < need->parser.mapx * W - 2)
        need->parser.posx+=2;
    if (keycode == 0 && need->parser.posx)
        need->parser.posx-=2;
    backGround(need);
    updatePos(need);
    confMinimap(need, &i, &j);
    miniMap(need, i, j);
    return 0;
}