#include "../includes/cub3d.h"
int location(char   *line, int len)
{
    while (line[len] == ' ')
        len++;
    return (len);
}
int     f_parse(void **p, int *code, char *str)
{
    char    **dstr;
    int     i;
    char    *strb;

    if (!str)
        return (1);
    strb  = ft_strtrim(str, " \n");
    free(str);
    if (!strb)
        return (1);
    dstr = ft_split(strb, ' ');
    i = 0;
    free(strb);
    if (!dstr)
        return (1);
    while(dstr[i])
        i++;
    if (i < 2 || ft_strlen(dstr[0]) > 2 || parse_seq(dstr[0]))
        return (d_free(dstr), 1);
    *code = dstr[0][1] + dstr[0][0];
    *p = ft_strdup(strb + location(strb , ft_strlen(dstr[0])));
    d_free(dstr);
    return (0);
}

int    setToPlace(void *p, int code, t_needs  *need)
{

    if (code == clac_seq("NO"))
        return (need->images[0]->file_name = p, 0);
    if (code == clac_seq("SO"))
        return (need->images[1]->file_name = p, 0);
    if (code == clac_seq("WE"))
        return (need->images[2]->file_name = p, 0);
    if (code == clac_seq("EA"))
        return (need->images[3]->file_name = p, 0);
    if (code == clac_seq("F"))
        return (need->colors[0] = p, 0);
    if (code == clac_seq("C"))
        return (need->colors[1] = p, 0);
    return 1;
}