# ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "all_structs.h"
//check_map.c
t_map	design_map(char *filename);

//utils
int		is_space(char c);
int		get_line(char **line, int fd, int key);

#endif