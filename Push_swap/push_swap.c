/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:57 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/09 11:09:28 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_num(char *str)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	key = 0;
	j = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && key == 0)
		{
			key = 1;
			j++;
		}
		else if (str[i] == ' ')
			key = 0;
		i++;
	}
	return (j);
}

void	same_value(int *num, int count)
{
	int	i;
	int	j;

	j = 0;
	while (j < count)
	{
		i = j + 1;
		while (i < count)
		{
			if (num[j] == num[i])
			{
				free(num);
				error("Error\n");
			}
			i++;
		}
		j++;
	}
}

int	*fix_num2(int *num, int *num2, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (num[i] == num2[j])
			{
				num[i] = j;
				j = len -1;
			}
			j++;
		}
		i++;
	}
	return (num);
}

int	*fix_num(int *num, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i - 1;
		while (++j < len)
		{
			if (num[i] > num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	return (num);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		count;

	if (ac > 1)
	{
		b = 0;
		a = add_stack(av, ac);
		count = count_stack(a);
		if (count <= 5)
			five_or_less(&a, &b);
		else
			radix(&a, &b, count);
		pree(a, b);
	}
	else
		exit (0);
}
