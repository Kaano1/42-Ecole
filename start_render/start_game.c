#include "../include/cub3d.h"

void	start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x + 0.5f;
	data->pos.y = map->y + 0.5f;
	data->look = (map->ang + 0) * ANLE_TO_RADIAN;
	render(data);
}
