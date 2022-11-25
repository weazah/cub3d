#include "../includes/cub3d.h"

int    f_parse(int *code, char *str)
{
    char    **dstr;
    int     i;

    if (!str)
        return NULL;
    dstr = ft_split(str);
    free(str);
    if (!dstr)
        return NULL;
    while(dstr[i])
        i++;
    if (i > 2 || ft_strlen(dstr[1]) > 2)
        return (d_free(dstr), NULL)
}

void    setToPlace(void *p, int code, t_needs  *need)
{

}