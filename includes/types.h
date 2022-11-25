#ifndef CUBTHREED_TYPES
#define CUBTHREED_TYPES

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	pad;
} t_color;
 
typedef struct s_images
{
	char	*file_name;
	void	*xpmptr;
	int		height;
	int		width;
} t_images;

typedef struct s_needs
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*colors[2];
	char		**map;
	t_images	*images[4];
	int			f;
	int			c;
} t_needs;

#endif