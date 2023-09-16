/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:55:10 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/19 16:01:59 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	else if (!(y == 0 && x > (int)ft_strlen(map[y - 1]))
		&& (is_space(map[y + 1][x])))
		return (1);
	else if (!(y == map_len(map) && x > (int)ft_strlen(map[y + 1]))
		&& (is_space(map[y + 1][x])))
		return (1);
	return (0);
}
