#include "../include/cub3d.h"

int	many_line(int fd)
{
	int	i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

void	Vazero(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	map->f.sta = 0;
	map->c.sta = 0;
	map->many_line = many_line(fd);
	close(fd);
}

t_map	*arrange_tMap(char *file)
{
	t_map	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFolder Error\n", 2);
		exit(1);
	}
	map = ft_calloc(sizeof(t_map), 1);
	Vazero(file, map);
	map = design_map(fd, map, 0);
	if (add_map(fd, map))
	{
		close(fd);
		clear_map_exit(map, ERROR_TAB);
	}
	check_characters(map);
	check_wall(map);
	if (map)
		get_position(map);
}
