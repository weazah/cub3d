#ifndef CUBTHREED_H
#define CUBTHREED_H
#include "../library/get_line/get_next_line.h"
#include "../library/libft/libft.h"
#include "mlx.h"
#include "types.h"
#include <stdio.h>
#include  <math.h>

#define resx 1920
#define resy 1080
#define bloc 20
#define ABS(N) ((N<0)?(-N):(N))

/* destruct source file region*/
void    d_free(char **d);
void    destructTextures(t_texture *tex, void   *mlx_ptr);
void    destructMap(t_map *map);
void    destructSheet(t_data    *data, void *mlx_ptr);
void    destruct(t_all *all, char   *message);
/*init source region */
void    init(t_all *all);
void    initPixels(t_all *all);

/* makeshift region*/
void    drawSquaredRegion(t_data *data, int y, int x, int color);
void    *get_pixel_location(t_data    *data, int x, int y);
void	pixel_to_image_put(t_data *data, int x, int y, int color);

/*parse region*/
void    startParse(t_all *all, char    *cub);
void    checkFileName(char  *file);
void    fitTex(t_all *all, char **tex);
int     getCode(char    *line);
int     notSpace(char   *line);
void    getTextures(t_all *all, int fd);
void    getMap(t_all *all, int fd);
void    setColors(t_all *all);
char    *skipNl(int fd);
int     mapChecker(char **map);

/*renders*/
    void    render(t_all *data);
    void    copyImage(t_data   *dest, t_data *src,int x, int y);
    void    set_pixel(int   *i, int j);
    double setRad(int deg);




#endif