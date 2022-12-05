#include "../includes/cub3d.h"

void    init(t_all *all)
{
    t_data  *data;

    data = &all->deps.sheet;
    all->deps.mlx_ptr = mlx_init();
    if (!all->deps.mlx_ptr)
        exit(1);
    all->deps.win_ptr[0] = mlx_new_window(all->deps.mlx_ptr, resx, resy, "cub3D");
    if (!all->deps.win_ptr[0])
        exit(1);
    data->img = mlx_new_image(all->deps.mlx_ptr, resx, resy);
    if (!data->img)
    {
        mlx_destroy_window(all->deps.mlx_ptr, all->deps.win_ptr[0]);
        exit(1);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
}

void    initPixels(t_all *all)
{
    int i;
    int x;
    int color;

    color = all->colors.ceiling;
    x = 0;
    i = 0;
    while (i < (resy))
    {
        if (i > (resy / 2))
            color = all->colors.floor;
        x = 0;
        while (x < resx)
        {
            set_pixel(get_pixel_location(&all->deps.sheet, x, i), color);
            x++;
        }
        i++;
    }

    mlx_put_image_to_window(all->deps.mlx_ptr, all->deps.win_ptr[0], all->deps.sheet.img, 0,0);
}

