#include "../../include/cub3d.h"

char	*add_NSWE(char *line, t_map *map)
{
	char	*send;
	int		i;

	i = 2;
	while (is_space(line[i]))
		i++;
	if (line[i] != '.' || line[i + 1] != '/')
		clear_map_exit(map, ERROR_NSWE);
	send = ft_substr(line, i, ft_strlen(line) - 1);
	return (send);
}