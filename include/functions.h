# ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "all_structs.h"

//utils
char	*add_NSWE(char *line, t_map *map);
t_pixel	add_Pixel(char *line, t_map *data);
void	clear_map_exit(t_map *data, char *str);
void	freeArray(char **str);
int		is_space(char c);
int		get_line(char **line, int fd, int key);

//check_map.c
t_map	*design_map(char *filename);

#endif