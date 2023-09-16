/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:19:59 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/17 17:25:50 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char *map)
{
	char	str;
	int		fd;
	int		i;
	int		control;

	fd = open(map, O_RDONLY);
	if (!fd)
		so_error("Error\nFile did not find!");
	i = 0;
	control = 1;
	while (control > 0)
	{
		control = read(fd, &str, 1);
		i++;
	}
	close(fd);
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_new_line(t_list *lst)
{
	int	j;
	int	counter;

	j = 0;
	counter = 1;
	while (lst->bf[j])
	{
		if (lst->bf[j] == '\n')
			counter++;
		j++;
	}
	if (lst->row != counter)
		so_error("Error\nRectangle error!\n");
	free(lst->bf);
}

void	*ft_calloc(size_t x, size_t size)
{
	void	*str;
	size_t	total;

	total = size * x;
	str = malloc(total);
	if (!str)
		return (0);
	while (total != 0)
	{
		((unsigned char *)str)[total - 1] = 0;
		total--;
	}
	return (str);
}
