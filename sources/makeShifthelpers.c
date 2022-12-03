#include "../includes/cub3d.h"
void    drawSquaredRegion(t_data *data, int *start, int *end, int color)
{
    int x;
    int y;
    
    x = start[0];
    y = start[1];
    while(y < end[1])
    {
         x = start[0];
        while (x  < end[0])
        {
            pixel_to_image_put(data, x, y, color);
            x++;
        }
        y++;
    }
}
   
void *get_pixel_location(t_data    *data, int x, int y)
{
    return (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
}

void	pixel_to_image_put(t_data *data, int x, int y, int color)
{
	unsigned    int *dst;

	dst = get_pixel_location(data, x, y);
    *dst = color;
}