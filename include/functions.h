/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:47:17 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 18:47:17 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "all_structs.h"

//parser
char	*add_NSWE(char *line, t_map *map);
t_pixel	add_pix(char *line, t_map *data, int sta, int i);
int		add_map(int fd, t_map *map);
int		get_line(char **line, int fd, int key);
int		check_characters(t_map *data);
int		check_wall(char **map, int y, int x);
void	ft_putstr_fd_err(char *s, int fd);
void	get_position(t_map *map);
t_map	*arrange_tMap(char *file);
t_map	*design_map(int fd, t_map *map, int i);

//utils
void	clear_map_exit(t_map *data, char *str);
void	free_array(char **str);
int		is_space(char c);

#endif