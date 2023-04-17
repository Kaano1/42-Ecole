/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:44:05 by ayumusak          #+#    #+#             */
/*   Updated: 2023/04/17 19:02:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	init_image(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen.width = WIN_WIDTH;
	data->screen.height = WIN_HEIGHT;
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	data->part_of_map.img = mlx_new_image(data->mlx, 200, 200);
	data->part_of_map.width = 200;
	data->part_of_map.height = 200;
	data->part_of_map.addr = mlx_get_data_addr(data->part_of_map.img, \
		&data->part_of_map.bbp, &data->part_of_map.line_len, \
			&data->part_of_map.endian);
}

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
