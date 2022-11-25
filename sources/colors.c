#include "../includes/cub3d.h"
int    miniCheck(int num)
{
    if (num < 0 || num > 255)
        return -1;
    return (num);
}
int not_anum(char   *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_isdigit(line[i]))
            return 1;
        i++;
    }
    return 0;
}
int setColor(char   **data, t_color *color)
{
    int num;
    color->pad = 0;
    num = ft_atoi(data[0]);
    if (miniCheck(num) == -1)
        return 1;
    color->r = num;
    num = ft_atoi(data[1]);
    if (miniCheck(num) == -1)
        return 1;
    color->g = num;
    num = ft_atoi(data[2]);
    if (miniCheck(num) == -1)
        return 1;
    color->b = num;
    return 0;
}
int checkColor(char **data,t_color *color)
{
    int i;

    i = 0;
    if (!data)
        return (1);
    while (data[i])
    {
        if (ft_strlen(data[i]) > 3 && ft_strlen(data[i]) != 0)
            return (d_free(data),1);
        if (not_anum(data[i]))
            return (d_free(data), 1);
        i++;
    }
    if (setColor(data, color))
        return (d_free(data), 1);
    
    return 0;
}
int getColors(t_needs *need)
{
	t_color	color;
    int     i;
    void *p = &color;

    i = 0;
    ft_bzero(&color, sizeof(t_color));
    while (i < 2)
    {
        if (checkColor(ft_split(need->colors[i], ','), &color))
            return (1);
        if (i == 0)
            need->f = *(int *)p;
        else
            need->c = *(int *)p;
        i++;
    }
    return 0;
}