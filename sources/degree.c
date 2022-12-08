#include "../includes/cub3d.h"

int setDegree(int *deg, int piv)
{
    *deg += piv;
    if (*deg > 360)
        *deg = *deg - 360;
    if (*deg < 0)
        *deg = *deg + 360;
    return *deg;
}

double setRad(int deg)
{
    return (deg * (M_PI / 180));
}