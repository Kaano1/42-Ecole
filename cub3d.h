#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <math.h>
# include "./help/libft/libft.h"
# include "./help/ft_printf/ft_printf.h"
# include "./help/gnl/get_next_line.h"

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
    t_map   *map;
    t_image game_img;
} t_data;

#endif
