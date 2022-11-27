#include "../includes/cub3d.h"

void    print_loc(t_needs *nee)
{
    printf("%s\n", nee->images[0]->file_name);
    printf("%s\n", nee->images[1]->file_name);
    printf("%s\n", nee->images[2]->file_name);
    printf("%s\n", nee->images[3]->file_name);
    printf("%s\n", nee->colors[0]);
    printf("%s\n", nee->colors[1]);
    printf("floor: %d\n", nee->f);
    printf("ceiling: %d\n", nee->c);

}
int main(int ac, char   **av)
{
    t_needs needs;
    if (ac != 2)
        return (ft_putstr_fd("./Cub3d <map file {*.cub}>\n",2), 1);
    ft_bzero(&needs, sizeof(t_needs));
    if (initData(&needs, av[1]))
        return 0;
    needs.mlx_ptr = mlx_init();
    if (!needs.mlx_ptr)
        return (1);
    printf("%d %d\n", needs.parser.mapy, needs.parser.mapx);
    needs.win_ptr = mlx_new_window(needs.mlx_ptr,
        needs.parser.mapx * W , needs.parser.mapy * H, "cub3D"); 
    if (!needs.win_ptr)
        return (1);
    mlx_key_hook(needs.win_ptr ,renderMap, &needs);
    mlx_loop(needs.mlx_ptr);
}