#include "../../include/cub3d.h"

char	*start_read(int fd)
{
	char	*line;

	while (get_line(&line, fd, 0) != -1)
	{
		if (ft_strrchr(line, '1'))
			return (line);
		free(line);
	}
	return (NULL);
}

int	add_map(int fd, t_map *map)
{
	int	i;
	char	*line;

	i = 0;
	line = start_read(fd);
	if (!line || line == NULL)
		return (1);
	map->map = ft_calloc(sizeof(char *), map->many_line);
	while (i < map->many_line)
	{
		map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	i = 0;
	while (i < map->many_line)
		printf("%s", map->map[i++]);
	return (0);
}
