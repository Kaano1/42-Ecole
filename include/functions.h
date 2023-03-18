# ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "all_structs.h"

//parser
char	*add_NSWE(char *line, t_map *map);
t_pixel	add_Pixel(char *line, t_map *data, int sta);
int		get_line(char **line, int fd, int key);
int		check_characters(t_data *data);
t_map	*arrange_tMap(char *file);
t_map	*design_map(int fd, t_map *map);

//utils
void	clear_map_exit(t_map *data, char *str);
void	freeArray(char **str);
int		is_space(char c);

#endif