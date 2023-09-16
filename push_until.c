/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:44:10 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/07 14:48:02 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f__k(t_list *av, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (av->i > av->next->i)
			return (1);
		av = av->next;
		i++;
	}
	return (0);
}

int	count_arg(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (ac-- != 1)
	{
		j = 0;
		while (av[ac][j + 1] != 0 && av[ac][j + 1] != ' ')
			j++;
		if (av[ac][j + 1] == ' ')
				i += calculate_num(av[ac]);
			j++;
		i++;
	}
	return (i);
}

int	ft_atoi_arg(char *str, int start)
{
	int	i;
	int	b;
	int	num;

	i = start;
	num = 0;
	b = 1;
	if (str[i] == '-')
	{
		b = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0 && str[i] != 32)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * b);
}
