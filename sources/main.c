#include "../includes/cub3d.h"

void    get_calcimg(t_all *all)
{
     t_data *data;
     t_data *data2;

    data = &all->deps.calcs;
    data2 = &all->deps.calcs2;
    all->deps.mlx_ptr = mlx_init();
    if (!all->deps.mlx_ptr)
        exit(1);
    all->deps.win_ptr = mlx_new_window(all->deps.mlx_ptr, all->map.x * bloc, all->map.y * bloc, "cub3Dmap");
    if (!all->deps.win_ptr)
        exit(1);
    data->img = mlx_new_image(all->deps.mlx_ptr, all->map.x * bloc, all->map.y * bloc);
    data2->img = mlx_new_image(all->deps.mlx_ptr, all->map.x * bloc, all->map.y * bloc);
    if (!data->img || !data2->img)
    {
        mlx_destroy_window(all->deps.mlx_ptr, all->deps.win_ptr);
        exit(1);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
    data2->addr = mlx_get_data_addr(data2->img, &data2->bits_per_pixel, &data2->line_length,&data2->endian);
    mlx_put_image_to_window(all->deps.mlx_ptr, all->deps.win_ptr, all->deps.calcs.img, 0,0);

}
int main(int ac, char   **av)
{
    t_all   data;
    if (ac != 2)
        return (ft_putstr_fd("the program needs two arguments",2), 1);
    ft_bzero(&data, sizeof(t_all));
    startParse(&data, av[1]);
    // init(&data);
    // initPixels(&data);
    get_calcimg(&data);
    render(&data);
    mlx_loop(data.deps.mlx_ptr);
}