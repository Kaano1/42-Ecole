#include "../../include/cub3d.h"

int	get_line(char **line, int fd, int key)
{
	char	*str;
	int		end_i;
	int		i;

	i = 0;
	str = get_next_line(fd);
	if (!str)
		return (-1);
	if (key != 1)
	{
		*line = str;
		return (1);
	}
	while (is_space(str[i]))
		i++;
	end_i = ft_strlen(str) - 1;
	while (is_space(str[end_i]))
		end_i--;
	*line = ft_substr(str, i, end_i);
	free(str);
	return (1);
}