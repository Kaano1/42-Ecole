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
# include <../lib/minilibx/mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef struct s_map
{
    char **map;
} t_map;

typedef struct s_data
{
    t_map			**map;
}t_data;

#endif
