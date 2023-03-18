#include "../include/cub3d.h"

int	design_map_continue(int i, char *line, t_map **map)
{
	if (i != -1 && !ft_strncmp(line, "NO ", 3))
		(*map)->no = add_NSWE(line, *map);
	else if (i != -1 && !ft_strncmp(line, "SO ", 3))
		(*map)->so = add_NSWE(line, *map);
	else if (i != -1 && !ft_strncmp(line, "WE ", 3))
		(*map)->we = add_NSWE(line, *map);
	else if (i != -1 && !ft_strncmp(line, "EA ", 3))
		(*map)->ea = add_NSWE(line, *map);
	else if (i != -1 && !ft_strncmp(line, "F ", 2))
		(*map)->f = add_Pixel(line + 2, *map, (*map)->f.sta);
	else if (i != -1 && !ft_strncmp(line, "C ", 2))
		(*map)->c = add_Pixel(line + 2, *map, (*map)->c.sta);
	else
		return (0);
	return (1);
}

t_map	*design_map(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (((!map->no || !map->so) || !map->we
		|| !map->ea || map->f.sta != 1 || map->c.sta != 1) && i != -1)
	{
		i = get_line(&line, fd, 1);
		if (design_map_continue(i, line, &map))
			free(line);
		else if (i != 42 && line != NULL)
		{
			free(line);
			clear_map_exit(map, ERROR_MAP);
		}
	}
	return (map);
}
