#ifndef CUBTHREED_H
#define CUBTHREED_H
#include "../library/get_line/get_next_line.h"
#include "../library/libft/libft.h"
#include "mlx.h"
#include "types.h"
#include <stdio.h>

#define resx 1920
#define resy 1080
#define W 10
#define H 10
#define floorM 0XFF2400
#define wallM 0XDBDECD
#define FRAMEW 15
#define FRAMEH 15
int     initData(t_needs *needs, char   *file);
int     initImages(t_needs *needs, int fd);
int     f_parse(void **p, int *code, char *str);
int    setToPlace(void *p, int code, t_needs  *need);
char    *skipNl(int fd);
void    d_free(char **str);
int     parse_seq(char  *line);
int     clac_seq(char   *line);
int     to_alocate(t_needs *needs, int code);
char    dfar(int num);
int not_anum(char   *line);
int checkColor(char **data,t_color *color);
int getColors(t_needs *need);
int getMap(t_needs *needs, int fd);
int mapChecker(char **map);
int zeroCheck(char  **map, int y, int x);
int checkVertical(char  **map, int y, int x);
int checkHorizontal(char  **map, int y, unsigned int x);
int    renderMap(int keycode, t_needs   *need);
int passable(char   c);




#endif