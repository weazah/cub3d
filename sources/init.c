#include "../includes/cub3d.h"

void    init(t_all *all)
{
    t_data  *data;

    data = &all->deps.sheet;
    all->deps.mlx_ptr = mlx_init();
    if (!all->deps.mlx_ptr)
        exit(1);
    all->deps.win_ptr = mlx_new_window(all->deps.mlx_ptr, resx, resy, "cub3D");
    if (!all->deps.win_ptr)
        exit(1);
    data->img = mlx_new_image(all->deps.mlx_ptr, resx, resy);
    if (!data->img)
    {
        mlx_destroy_window(all->deps.mlx_ptr, all->deps.win_ptr);
        exit(1);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
}

void    initPixels(t_all *all)
{
    int places[4];
    ft_bzero(&places, sizeof(places));
    places[3] = resy / 2;
    places[2] = resx;
    drawSquaredRegion(&all->deps.sheet, places, places + 2, all->colors.floor);
    places[1] = resy / 2;
    places[3] = resy;
    drawSquaredRegion(&all->deps.sheet, places, places + 2, all->colors.ceiling);
    mlx_put_image_to_window(all->deps.mlx_ptr, all->deps.win_ptr, all->deps.sheet.img, 0,0);
}