#ifndef CUBTHREED_H
#define CUBTHREED_H
#include "../library/get_line/get_next_line.h"
#include "../library/libft/libft.h"
#include "mlx.h"
#include "types.h"
#include <stdio.h>

#define resx 1920
#define resy 1080
#define bloc 10; 

/* destruct source file region*/
void    destructTextures(t_texture *tex, void   *mlx_ptr);
void    destructMap(t_map *map);
void    destructSheet(t_data    *data, void *mlx_ptr);
void    destruct(t_all *all);
/*init source region */
void    init(t_all *all);
void    initPixels(t_all *all);

/* makeshift region*/
void    drawSquaredRegion(t_data *data, int *start, int *end, int color);
void *get_pixel_location(t_data    *data, int x, int y);
void	pixel_to_image_put(t_data *data, int x, int y, int color);

/*parse region*/
void    startParse(t_all *all, char    *cub);


#endif