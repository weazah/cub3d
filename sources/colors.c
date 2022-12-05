#include "../includes/cub3d.h"

int checkcolor(char *line)
{
    int i;
    int p;

    p = 0;
    i = -1;
    while (line[++i])
    {
       if (line[i] == ',')
        p++;
        if (!(ft_isdigit(line[i]) || line[i] == ','))
            return (1);
        if (line[i] == ',' && line[i + 1] == ',')
            return 1;
    }
    if (p == 2 && ft_isdigit(line[0]))
        return (0);
    return (1);
}
int passC(t_all *all, char  *line)
{
    int i;
    int n;

    i = ft_strlen(line);
    if (i == 0 || i > 3)
        destruct(all, "error\ninvalid Color\n");
    n = ft_atoi(line);
    if (n > 255)
        destruct(all, "error\ninvalid Color\n");
    return n;
}
unsigned int    retColor(t_all *all, char   **color)
{
    t_color colorst;
    int i;
    unsigned int *c;

    i = 0;
    if (!color)
        destruct(all, "error\n in split\n");
    if (!color[0] || !color[1] || !color[2] || color[3])
        destruct(all, "error\nsomething bigger than us\n");
    colorst.r = passC(all, color[0]);
    colorst.g = passC(all, color[1]);
    colorst.b = passC(all, color[2]);
    c = (unsigned int *)&colorst;
    return (*c);
}
unsigned int getColor(t_all *all, int what)
{
    char    *color;
    int i;

    if (!what)
        color = all->colors.sceiling;
    else
        color = all->colors.sfloor;
    if (checkcolor(color))
        destruct(all, "error\nin color\n");    
    return (retColor(all,ft_split(color, ',')));
}
void    setColors(t_all *all)
{
    all->colors.ceiling = getColor(all,0);
    all->colors.floor = getColor(all,1);
}