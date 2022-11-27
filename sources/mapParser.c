#include "../includes/cub3d.h"

char	*mapStore(char	*line, int mode)
{
	static	char	*store;
	char	*temp;

	if (mode == 1)
		return (store);
	if (mode == 2)
		return (free(store), NULL);
	if (!store)
		return (store = ft_strdup(line), NULL);
	temp = store;
	store = ft_strjoin(store, line);
	free(temp);
	return NULL;
}

int thatSpace(t_parser *parser, char   *line)
{
    int i;
	int len;

	len = ft_strlen(line);
	if (len > parser->mapx && line[len - 1] == '\n')
		parser->mapx = len -1;
	else if (len > parser->mapx)
			parser->mapx = len;
    i = 0;
    while(line[i])
    {
		if (line[i] != ' ')
			break ;
		i++;
    }
	
	if (line[i] == '\n')
		return (1);
    return 0;
}
int noPass(char	*line,t_parser *parser)
{
	int i;

	i = 0;
	if (thatSpace(parser, line))
		return (free(line), 1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			i++;
		else	if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W')
			{
				if (!parser->D)
					parser->D = line[i];
				else
					return (free(line), 1);
				i++;
			}
		else
			return (free(line), 1);
	}
	return (0);
}

char	*readMap(t_needs *needs, int fd)
{
	char	*line;

	line = skipNl(fd);
	if (!line)
		return NULL;
	if (noPass(line, &needs->parser))
			return (mapStore(NULL , 2), NULL);
	mapStore(line, 0);
	while (1)
	{
		needs->parser.mapy++;
		line = get_next_line(fd);
		if (!line)
			return (mapStore(NULL, 1));
		if (noPass(line, &needs->parser))
			return (mapStore(NULL , 2), NULL);
		mapStore(line , 0);
		free(line);
	}
	return (NULL);
}

int getMap(t_needs *needs, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
    needs->map = ft_split(readMap(needs, fd), '\n');
    if (!needs->map || !needs->parser.D)
        return (1);
	while (needs->map[i])
	{
		j = 0;
		while (needs->map[i][j])
		{
			if (needs->map[i][j] == needs->parser.D)
				{
					needs->parser.posx = j * W;
					needs->parser.posy = i * H;
				}
			j++;
		}
		i++;
	}
    return 0;
}