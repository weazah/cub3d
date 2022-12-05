#include "../includes/cub3d.h"

void    setDegree(int *deg)
{
    if (*deg > 360)
        *deg = *deg - 360;
    if (*deg < 0)
        *deg = *deg + 360;
}

double setRad(int deg)
{
    return (deg * (M_PI / 180));
}