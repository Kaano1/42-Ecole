/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:32:23 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/09 11:12:54 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*add(int *num, int len)
{
	int	*num2;
	int	i;

	num2 = malloc(sizeof(int) * len + 1);
	if (!num2)
		exit (-1);
	i = 0;
	while (i < len)
	{
		num2[i] = num[i];
		i++;
	}
	return (num2);
}

int	big_bit(int a)
{
	int	i;

	i = 0;
	while (a != 0)
	{
		a = a >> 1;
		i++;
	}
	return (i);
}

void	radix(t_list **a, t_list **b, int ac)
{
	int	i;
	int	max;
	int	count;

	max = big_bit(ac);
	i = 0;
	while (i < max)
	{
		count = ac;
		while (count != 0)
		{
			if ((((*a)->i >> i) & 1) == 1)
				rotate(a, 'a');
			else
				push_stack(a, b, 'b');
			count--;
		}
		while ((*b) != 0)
			push_stack(b, a, 'a');
		i++;
	}
}
