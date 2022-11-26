#include "../includes/cub3d.h"

int passable(char   c)
{
    if (c  == 'W' || c == 'E' || c == 'S' ||c =='N')
        return 1;
    return 0;
}

int checkHorizontal(char  **map, int y, unsigned int x)
{
    int i;

    i = y;
    while (i && (map[i][x] == '0' || passable(map[i][x])))
    {
        i--;
        if (i && ft_strlen(map[i]) < x)
            return 1;
    }
    if (map[i][x] != '1')
        return 1;
    i = y;
    while (map[i] && i && (map[i][x] == '0' || passable(map[i][x])))
    {
        i++;
        if (!map[i])
            return 1;
        if (i && ft_strlen(map[i]) < x)
            return 1;
    }
    if (map[i][x] != '1')
        return 1;
    return 0;
}

int checkVertical(char  **map, int y, int x)
{
    int i;

    i = x;
    while(map[y][i] == '0'|| passable(map[y][i]))
        i++;
    if (map[y][i] != '1')
        return 1;
    i = x;
    while(i && (map[y][i] == '0' || passable(map[y][i])))
        i--;
    if (map[y][i] != '1' )
        return 1;
    return 0;
}
int zeroCheck(char  **map, int y, int x)
{
    if (checkHorizontal(map, y,x))
        return 1;
    if (checkVertical(map, y, x))
        return 1;
    return 0;
}
int mapChecker(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0' && zeroCheck(map, i, j))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}