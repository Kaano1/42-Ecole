#include "../include/cub3d.h"

void	ft_putstr_fd_err(char *s, int fd)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i] != 0)
			write(fd, &s[i++], 1);
	}
	exit(1);
}

int	check_characters(t_map *data)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	a = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!is_space(data->map[i][j]) && !ft_strchr("01NSEW", data->map[i][j]))
			{
				printf("(%d)---%d/%d\n", data->map[i][j], i, j);
				ft_putstr_fd_err("Error\nInvalid Character\n", 2);
			}
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
				a++;
		}
	}
	if (a != 1)
			ft_putstr_fd_err("Error\nMore than one char\n", 2);
	return (1);
}


int	check_wall(t_map *game)
{
	int	j;
	int	i;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (!(game->map[i][++j]))
		{
			if(game->map[i][++j] != 1)
			{
				if((game->map[i][j+ 1] == '\t') || (game->map[i][j + 1] == ' ') \
				||(game->map[i][j - 1] == '\t') || (game->map[i][j - 1] == ' ') \
				||(game->map[i + 1][j] == '\t') || (game->map[i + 1][j] == ' ') \
				||(game->map[i -1 ][j] == '\t') || (game->map[i -1][j] == ' '))
					ft_putstr_fd_err("WALL ERROR\n", 2);
			}
		}

}
	return(1);
}
