#include "../includes/cub3d.h"

int	initImages(t_needs *needs, int fd)
{
	void	*p;
	int		i;
	int		code;

	i = 0;
	p = NULL;
	while (i < 6)
	{
		if (f_parse(&p, &code, skipNl(fd)))
			return (close(fd), 1);
		if (!p)
			return (close(fd),1);
		if (to_alocate(needs, code))
			return (close(fd),1);
		setToPlace(p, code, needs);
		i++;
	}
	return (0);
}

int initData(t_needs *needs , char	*file)
{
	int fd;

	if (ft_strlen(file) < 3 || ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		return (ft_putstr_fd("Wrong extention\n", 2), 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("file doesnt exist\n", 2), 1);
	if (initImages(needs, fd))
		return (1);
	if (getColors(needs))
		return (1);
	if (getMap(needs,fd))
		return (1);
	if (mapChecker(needs->map))
		return 1;
	printf("%d, %d\n", needs->parser.posx,needs->parser.posy );
    return (0);
}