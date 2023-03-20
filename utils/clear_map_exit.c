/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:57:17 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 18:57:17 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_map_exit(t_map *data, char *str)
{
	int	i;

	ft_putstr_fd(str, 2);
	if (data->no)
		free(data->no);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->so)
		free(data->so);
	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	if (data->map)
		free(data->map);
	free(data);
	exit (1);
}
