#include "../include/cub3d.h"

int	get_line(char **line, int fd, int key)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (str[i])
}