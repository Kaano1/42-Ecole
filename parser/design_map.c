/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:57:21 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 19:19:39 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	design_map_continue(int i, char **line, t_map **map, int fd)
{
	if (i != 42 && *line != NULL)
	{
		close(fd);
		clear_map_exit(*map, ERROR_MAP);
	}
	return (1);
}

t_map	*design_map(int fd, t_map *map, int i)
{
	char	*line;

	while (((!map->no || !map->so) || !map->we
			|| !map->ea || map->f.sta != 1 || map->c.sta != 1) && i != -1)
	{
		i = get_line(&line, fd, 1);
		if (i != -1 && !ft_strncmp(line, "NO ", 3))
			map->no = add_NSWE(line, map);
		else if (i != -1 && !ft_strncmp(line, "SO ", 3))
			map->so = add_NSWE(line, map);
		else if (i != -1 && !ft_strncmp(line, "WE ", 3))
			map->we = add_NSWE(line, map);
		else if (i != -1 && !ft_strncmp(line, "EA ", 3))
			map->ea = add_NSWE(line, map);
		else if (i != -1 && !ft_strncmp(line, "F ", 2))
			map->f = add_pix((line + 2), map, map->f.sta, 0);
		else if (i != -1 && !ft_strncmp(line, "C ", 2))
			map->c = add_pix((line + 2), map, map->c.sta, 0);
		else
			design_map_continue(i, &line, &map, fd);
		map->many_line--;
		free(line);
	}
	return (map);
}
