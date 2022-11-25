#ifndef CUBTHREED_H
#define CUBTHREED_H
#include "../library/get_line/get_next_line.h"
#include "../library/libft/libft.h"
#include "mlx.h"
#include "types.h"
#include <stdio.h>

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





#endif