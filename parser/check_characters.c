/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:50:49 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 18:50:49 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if ((!is_space(data->map[i][j])) &&
				(!ft_strchr("01NSEW", data->map[i][j])))
				clear_map_exit(data, ERROR_VAL);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
				a++;
		}
	}
	if (a != 1)
		ft_putstr_fd_err("Error\nMore than one char\n", 2);
	return (0);
}

void	recursive_check(char **map, int y, int x, int key, int *rs)
{
	static int _x;
	static int _y;

	map[y][x] = '2';
	if (key == 1)
	{
		_x = x;
		_y = y;
		map[y][x] = '1';
	}
	if (map[y][x + 1] == '1')
		recursive_check(map, y, x + 1, key + 1, rs);
	if (y != 0 && map[y][x - 1] == '1')
		recursive_check(map, y, x - 1, key + 1, rs);
	if (key != 1 && map[y + 1] != 0 && map[y + 1][x] == '1')
		recursive_check(map, y + 1, x, key + 1, rs);
	if (y != 0 && map[y - 1][x] == '1')
		recursive_check(map, y - 1, x, key + 1, rs);
	if (key != 1 && _x == x && _y == y)
	{
		*rs = 1;
		return ;
	}
}

void	printMap(char **map)
{
	int	i = 0;
	int j = 0;

	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%c", map[j][i]);
			i++;
		}
		j++;
	}
}

int	check_wall(char **map, int y, int x)
{
	int		result;

	result = 0;
	while (is_space(map[y][x]))
		x++;
	recursive_check(map, y, x, 1, &result);
	if (result == 0)
		return (1);
	printMap(map);
	return (0);
}


/*
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
			if (game->map[i][++j] != 1)
			{
				if ((game->map[i][j + 1] == '\t') || (game->map[i][j + 1] == ' ') \
				||(game->map[i][j - 1] == '\t') || (game->map[i][j - 1] == ' ') \
				||(game->map[i + 1][j] == '\t') || (game->map[i + 1][j] == ' ') \
				||(game->map[i - 1][j] == '\t') || (game->map[i - 1][j] == ' '))
					ft_putstr_fd_err("WALL ERROR\n", 2);
			}
		}

}
	return(1);
}
*/
