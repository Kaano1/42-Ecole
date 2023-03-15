# ifndef ALL_STRUCTS_H
# define ALL_STRUCTS_H

typedef struct s_pix
{
	int	r;
	int	g;
	int	b;
} t_pix;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
} t_image;

typedef struct s_map
{
	char *so;
	char *no;
	char *we;
	char *ea;
	char **map;
} t_map;

typedef struct s_data
{
	t_map	*map;
	t_image game_img;
	t_pix	f;
	t_pix	c;
} t_data;

#endif