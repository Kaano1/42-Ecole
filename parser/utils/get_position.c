#include "../../include/cub3d.h"

void	get_position(t_map *data)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (data->map[++i])
	{
		k = -1;
		while (data->map[i][++k])
		{
			if (ft_strchr("WESN", data->map[i][k]))
			{
				while (data->map[i][k] != "ENWS"[t])
					t++;
				data->ang = t * 90;
				data->map[i][k] = '0';
				data->y = i;
				data->x = k;
				return ;
			}
		}
	}
}
