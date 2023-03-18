#include "../include/cub3d.h"

void	Vazero(t_map *map)
{
	map->f.sta = 0;
	map->c.sta = 0;
}

t_map	*arrange_tMap(char *file)
{
	t_map	*map;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFolder Error\n", 2);
		exit(1);
	}
	map = ft_calloc(sizeof(t_map), 1);
	Vazero(map);
	map = design_map(fd, map);
}
