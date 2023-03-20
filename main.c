/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:44:05 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 18:45:39 by ayumusak         ###   ########.fr       */
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
	}
	else
		ft_putstr_fd("Error\nArgument Error\n", 2);
}
