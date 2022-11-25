#include "../includes/cub3d.h"

void    leaks(void)
{
    system("leaks Cub3d");
}
int main(int ac, char   **av)
{
    atexit(leaks);
    if (ac != 2)
        return (ft_putstr_fd("./Cub3d <map file {*.cub}>\n",2), 1);
    t_needs needs;
    ft_bzero(&needs, sizeof(t_needs));
    if (initData(&needs, av[1]) == 0)
        return 0;
    printf("success");
}