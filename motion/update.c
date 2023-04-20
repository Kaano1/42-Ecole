/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:51 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/19 15:06:51 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	update(t_data *data)
{
	float		speed;
	float		look_speed;
	t_vector2f	movement;

	speed = 0.08f;
	if (data->keys.speed)
		speed = 0.3f;
	look_speed = 0.03f;
	movement = (t_vector2f){0, 0};
	movement.x += cosf(data->look) * speed * (data->keys.w - data->keys.s);
	movement.y += sinf(data->look) * speed * (data->keys.w - data->keys.s);
	movement.x += cosf(data->look + (PI / 2)) * speed * \
	(data->keys.a - data->keys.d);
	movement.y += sinf(data->look + (PI / 2)) * speed * \
	(data->keys.a - data->keys.d);
	if (data->keys.left)
		data->look += look_speed;
	if (data->keys.right)
		data->look -= look_speed;
	move(data, movement);
	render(data);
	return (0);
}
