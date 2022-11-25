#include "../includes/cub3d.h"
int	initImages(t_needs *needs, int fd)
{
	void	*p;
	int		i;
	int		code;

	needs->images = ft_calloc(6, sizeof(void *));
	if (!needs->images)
		return (1);
	i = 0;
	p = NULL;
	while (i < 6)
	{
		p = f_parse(&p, &code, skipNl(fd));
		if (!p)
			return (1)
		setToPlace(p, code, needs);
		i++;
	}
}
int initData(t_needs *needs , char	*file)
{
	int fd;

	if (ft_strlen(file) < 3 || ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		return (ft_putstr_fd("Wrong extention\n", 2), 0);
	fd = open("file", O_RDONLY);
	if (fd < 0 || initImages(needs, fd))
		return (0);
	needs->mlx_ptr = mlx_init();
	if (!needs->mlx_ptr)
		return 0;
	fd = 0;
    return (1);
}