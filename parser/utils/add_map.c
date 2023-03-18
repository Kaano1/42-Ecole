#include "../../include/cub3d.h"

char	*start_read(int fd)
{
	char	*line;

	while (get_line(&line, fd, 0) != -1)
	{
		if (!ft_strncmp(line, "1", ft_strlen(line)))
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
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	return (0);
}