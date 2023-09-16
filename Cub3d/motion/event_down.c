/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:30 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/19 15:06:30 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	event_down(int key, t_data *data)
{
	if (key == 13 || key == 119)
		data->keys.w = 0;
	else if (key == 1 || key == 115)
		data->keys.s = 0;
	else if (key == 0 || key == 97)
		data->keys.a = 0;
	else if (key == 2 || key == 100)
		data->keys.d = 0;
	else if (key == 123)
		data->keys.left = 0;
	else if (key == 124)
		data->keys.right = 0;
	else if (key == 257)
		data->keys.speed = 0;
	return (0);
}
