#include "../includes/cub3d.h"

void    print_loc(t_needs *nee)
{
    printf("%s", nee->images[0]->file_name);
    printf("%s", nee->images[1]->file_name);
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
    //print_loc(&needs);
}