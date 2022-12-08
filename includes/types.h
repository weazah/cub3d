#ifndef CUBTHREED_TYPES
#define CUBTHREED_TYPES

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef enum s_dir
{
	N,
	E,
	W,
	S
}	t_dir;

typedef	struct s_player
{
	double	px_y;
	double px_x;
	int	y;
	int	x;
	int dire;
	double rad;
}	t_player;

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	pad;
} t_color;

typedef struct s_colors
{
	unsigned	int ceiling;
	unsigned int floor;
	char	*sceiling;
	char	*sfloor;
} t_colors;

typedef struct  s_map
{
	char	**map;
	int		y;
	int		x;
}	t_map;

typedef struct s_texture
{
	char	*file;
	void	*raw;
	int		height;
	int 	width;
	double	angle;
} t_texture;

typedef struct s_deps
{
	void	*mlx_ptr;
	void	*win_ptr[2];
	t_data	sheet;
	t_data	calcs;
	t_data	calcs2;
} t_deps;

typedef struct s_all
{
	t_deps		deps;
	t_texture	texs[4];
	t_map 		map;
	t_colors	colors;
	t_player	player;
} t_all;

#endif