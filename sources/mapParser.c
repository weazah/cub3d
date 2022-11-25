#include "../includes/cub3d.h"
char	*customStrjoin(char  *s1, char *s2)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

	j = 0;
    if (!s1)
        return NULL;
	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	ss = malloc((ln1 + ln2) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s1, ln1);
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	return (free(s1), free(s2), ss);
}
char *readMap(int fd)
{
    
	char	*map;
	char	*join;
    
	join = NULL;
	map = skipNl(fd);
    if (!map)
        return NULL;
	while (1)
	{
		
		join = get_next_line(fd);
		if (!join)
			break ;
		map = ft_strjoin(map, join);
        if (!map)
            return (NULL);
	}
    return (map);
}

int getMap(t_needs *needs, int fd)
{
    needs->map = ft_split(readMap(fd), '\n');
    if (!needs->map)
        return 1;
    return 0;
}