#include "../include/cub3d.h"

t_map	*design_map(char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFolder Error\n", 2);
		exit(1);
	}
	map = ft_calloc(sizeof(t_map), 1);
	while (i != -1)
	{
		i = get_line(&line, fd, 1);
		if (!ft_strncmp(line, "NO ", 3))
			map->no = add_NSWE(line, map);
		else if (!ft_strncmp(line, "SO ", 3))
			map->so = add_NSWE(line, map);
		else if (!ft_strncmp(line, "wE ", 3))
			map->we = add_NSWE(line, map);
		else if (!ft_strncmp(line, "EA ", 3))
			map->ea = add_NSWE(line, map);
		else if (!ft_strncmp(line, "F ", 2))
			map->f = add_Pixel(line + 2, map);
		else if (!ft_strncmp(line, "C ", 2))
			map->c = add_Pixel(line + 2, map);
		else if (!ft_strncmp(line, "1", ft_strlen(line)))
		{

		}
		else if (line != NULL)
		{
			free(line);
			clear_map_exit(map, ERROR_MAP);
		}
		free(line);
	}
	return (map);
}
