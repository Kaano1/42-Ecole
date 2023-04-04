/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:44:05 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/04 17:39:31 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if (ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 5))
	{
		map = arrange_tMap(av[1]);
		check_characters(map);
		if (check_wall(map->map, 0, 0))
			clear_map_exit(map, ERROR_MAP);
		if (map)
			get_position(map);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "...");
		get_data(&data, map);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument Error\n", 2);
}
