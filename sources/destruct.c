#include "../includes/cub3d.h"

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
    int i;

    i = 0;
    while (map->map && map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    if (map->map)
        free(map->map);
}
void    destructSheet(t_data    *data, void *mlx_ptr)
{
    if (data->img)
        mlx_destroy_image(mlx_ptr, data->img);
}

void    destruct(t_all *all)
{
    destructTextures(&all->texs[0], all->deps.mlx_ptr);
    destructMap(&all->map);
    destructSheet(&all->deps.sheet, all->deps.mlx_ptr);
    exit(1);
}