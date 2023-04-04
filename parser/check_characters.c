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

void	printMap(char **map)
{
	int	i = 0;
	int j = 0;

	while (map[j])
	{
		i = 0;
		printf("%d.", j);
		while (map[j][i])
		{
			printf("%c", map[j][i]);
			i++;
		}
		j++;
	}
	printf("\n");
}
//0 ların 4 tarafına bakabiliriz ardından 0 ların içerisinde flood_fill yapabiliriz ve içerisinde boşluk varsa açtırmayabiliriz.

int	map_len(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	condition(char **map, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (x != 0 && is_space(map[y][x + 1]))
		return (1);
	else if (map[y][x + 1] == 0 || is_space(map[y][x + 1]))
		return (1);
	else if (!(y == 0 && x > ft_strlen(map[y - 1])) &&
		(is_space(map[y + 1][x])))
		return (1);
	else if (!(y == map_len(map) && x > ft_strlen(map[y + 1])) &&
			(is_space(map[y + 1][x])))
		return (1);
	return (0);
}

int	checking_zero(char **map, int y, int x)
{
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && condition(map, y, x))
			{
				map[y][x] = 'X';
				printMap(map);
				printf("%c--%d--%d", map[y][x], y, x);
				return (1);
			}
			x++;
		}
	}
	return (0);
}

int	check_double_map(char **map, int y, int x)
{
	int	key;

	key = 0;
	while (map[y])
	{
		if (ft_strchr(" ", map[y][x]) && key == 0 &&
			(!ft_strchr("01NSEW", map[y][x])))
			key++;
		else if ((!ft_strchr(" 01NSEW", map[y][x])) &&
			key == 1)
			return (1);
		y++;
	}
	return (0);
}

//invalid texture,
int	check_wall(char **map, int y, int x)
{
	if (check_double_map(map, y, x))
		return (1);
	if (checking_zero(map, y - 1, x))
		return (1);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '\n' && is_space(map[y][x]))
				map[y][x] = '1';
			x++;
		}
		y++;
	}
	printMap(map);
	return (0);
}

//birebir aynı yada alt tarafın tamamıyla 1 olması durumunda
//yukarının ince bir şekilde dizayn edilmesi gerekiyor.

//çözüm:
//duvarlar 2 ye çevrilir o sırada açıkta kalan 1 veya 0 olan bir değer
//var mı diye kontrol
//başta 0 var mı diye ön kontroller doğru yapacağız her zaman 
//0 ıncı indexte olması imkansız ardından fazla olan 2 leri space
//yapacak bir şey yapmamız gerekiyor.
//sonrasında tekrar 1 e dönüştüreceğiz
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
