#include "../includes/cub3d.h"

void    d_free(char **d)
{
    int i;

    i = 0;
    if (!d)
        return ;
    while (d[i])
    {
        free(d[i]);
        i++;
    }
    free(d);
}
void    destructTextures(t_texture *tex, void   *mlx_ptr)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (tex[i].file)
            free(tex[i].file);
        if (tex[i].raw)
            mlx_destroy_image(mlx_ptr, tex[i].raw);
        i++;
    }
}
void    destructMap(t_map *map)
{
    if (map->map)
        d_free(map->map);
}
void    destructSheet(t_data    *data, void *mlx_ptr)
{
    if (data->img)
        mlx_destroy_image(mlx_ptr, data->img);
}

void    destruct(t_all *all, char   *message)
{
    if (message)
        ft_putstr_fd(message, 2);
    destructTextures(&all->texs[0], all->deps.mlx_ptr);
    destructMap(&all->map);
    destructSheet(&all->deps.sheet, all->deps.mlx_ptr);
    exit(1);
}