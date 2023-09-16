/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:37 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/19 15:06:37 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_screen(void *tmp)
{
	(void)tmp;
	exit(0);
}

void	motion_setting(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, event_up, data);
	mlx_hook(data->mlx_win, 3, 0, event_down, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->mlx_win, 17, 0, exit_screen, 0);
}
