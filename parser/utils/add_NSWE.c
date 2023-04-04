/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_NSWE.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:57:43 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/20 18:57:43 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_test(char *line, int start, int end)
{
	while (start < end)
	{
		if (is_space(line[start]))
			return (1);
		start++;
	}
	return (0);
}

char	*add_NSWE(char *line, t_map *map)
{
	char	*send;
	int		i;
	int		len;

	i = 2;
	len = ft_strlen(line) - 1;
	while (is_space(line[i]))
		i++;
	while (is_space(line[len]))
		len--;
	if (line[i] != '.' || line[i + 1] != '/' || ft_test(line, i, len))
		clear_map_exit(map, ERROR_NSWE);
	send = ft_substr(line, i, ft_strlen(line) - 1);
	return (send);
}