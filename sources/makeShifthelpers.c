#include "../includes/cub3d.h"

void    drawSquaredRegion(t_data *data, int y, int x, int color)
{
    int ty;
    int tx;

    ty = y + bloc + 1;
    tx = x;
    while(y < ty)
    {
        x = tx;
        while (x  < tx + bloc)
        {
            pixel_to_image_put(data, x, y, color);
            x++;
        }
        y++;
    }
}
void *get_pixel_location(t_data    *data ,int x, int y)
{
    int *image_buffer;
    int line;

    line = data->line_length / 4;
    image_buffer = (int *)data->addr;
    return (&image_buffer[y * line + x]);
}

void	pixel_to_image_put(t_data *data, int x, int y, int color)
{
	int *dst;

	dst = get_pixel_location(data, x, y);
    *dst = color;
}
int get_pixel_color(t_data    *data, int x, int y)
{
    int *image_buffer;
    int line;

    line = data->line_length / 4;
    image_buffer = (int *)data->addr;
    return (image_buffer[y * line + x]);
}
void    set_pixel(int   *i, int j)
{
    *i = j;
}
void    copyImage(t_data   *dest, t_data *src,int x, int y)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x)
        {
            set_pixel(get_pixel_location(dest, i , j), get_pixel_color(src, i, j));
            i++;
        }
        j++;
    }

}