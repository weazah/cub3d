#include "../includes/cub3d.h"


int main(int ac, char   **av)
{
    t_all   data;
    if (ac != 2)
        return (ft_putstr_fd("the program needs two arguments",2), 1);
    ft_bzero(&data, sizeof(t_all));
    startParse(&data, av[1]);
    init(&data);
    printf("%d %d \n", data.map.x, data.map.y);
    // initPixels(&data);
    // mlx_loop(data.deps.mlx_ptr);
}