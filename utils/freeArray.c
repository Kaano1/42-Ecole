#include "../include/cub3d.h"

void	freeArray(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}