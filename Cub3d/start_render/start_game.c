/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:43:35 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/19 14:43:35 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x + 0.5f;
	data->pos.y = map->y + 0.5f;
	data->look = (map->ang + 180) * ANLE_TO_RADIAN;
	render(data);
}
