#include "../includes/cub3d.h"

static  char    *store(char  *line, int mode)
{
    static char    *all;
    char    *temp;

    if (!mode)
        {
            free(all);
            return NULL;
        }
    if (mode == 1)
        return all;
    if (!all)
        {
            all = ft_strdup(line);
            return NULL;
        }
    temp = all;
    all = ft_strjoin(all, line);
    free(temp);
    return all;
}
int notAllowed(t_all *all, char c, int index)
{
    if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
    {
        if (all->player.dire)
            return 1;
        all->player.dire = c;
        all->player.x = index;
        return 0;
    }
    if (c == '0' || c == '1' || c == ' ' )
        return 0;
    return (1);
}
int mapRules(t_all *all,char   *line)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(line);
    if (len > all->map.x)
        all->map.x = len;
    if (len == 0)
        return (1);
    while (i < len)
    {
        if (notAllowed(all, line[i], i))
            return (1);
        i++;
    }
    if (!all->player.dire)
        all->player.y++;
    all->map.y++;
    return (0);
}
void    getMap(t_all *all, int fd)
{
    char    *line;
    char    *al;

    line = skipNl(fd);
    while (1)
    {
        if (!line)
            break ;
        if (mapRules(all, ft_strtrim(line, "\n")))
        {
            store(NULL, 0);
            destruct(all, "Error\n map\n");
        }
        store(line, 2);
        free(line);
        line = get_next_line(fd);
    }
    al = store(NULL, 1);
    if (!al)
        destruct(all, "Error\n map\n");
    all->map.map = ft_split(al, '\n');
}