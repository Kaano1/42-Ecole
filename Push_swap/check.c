/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:15 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/07 14:48:23 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_arg(int *num, int *index, char *str)
{
	int	j;
	int	i;

	j = 0;
	i = *index;
	while (str[j])
	{
		if ((str[j] >= '0' && str[j] <= '9') || str[j] == '-')
		{
			num[i] = ft_atoi_arg(str, j);
			while (str[j] != 32 && str[j] != 0)
				j++;
			i++;
		}
		j++;
	}
	*index = i;
}

int	*convert_int(char **av, int ac)
{
	int	*num;
	int	c;
	int	j;
	int	i;

	num = malloc(sizeof(int) * count_arg(av, ac) * 100);
	if (!num)
		exit (-1);
	i = 0;
	c = 1;
	while (c < ac)
	{
		j = 0;
		while (av[c][j] != ' ' && av[c][j] != 0)
			j++;
		if (av[c][j] == ' ')
			convert_arg(num, &i, av[c]);
		else
			num[i] = ft_atoi(av[c]);
		i++;
		c++;
	}
	return (num);
}

void	check_dif_char(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
			error("Error\n");
		check_arg(av[i]);
		i++;
	}
}

void	look_num(int *num, int *num2, int len)
{
	int	i;

	i = 0;
	while (num[i] == num2[i] && i < len)
		i++;
	if (i == len)
	{
		free(num);
		free(num2);
		exit (0);
	}
}

int	*check(char **av, int ac)
{
	int	*num;
	int	*num2;
	int	count;

	check_dif_char(av, ac);
	num = convert_int(av, ac);
	count = count_arg(av, ac);
	same_value(num, count);
	num2 = fix_num(add(num, count), count);
	look_num(num, num2, count);
	num = fix_num2(num, num2, count);
	free(num2);
	return (num);
}
