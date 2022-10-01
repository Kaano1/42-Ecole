/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less5_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:01 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:25 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_2(t_list **a)
{
	if ((*a)->i > (*a)->next->i)
		swap(a, 'a');
}

void	solve_3(t_list **a)
{
	solve_2(a);
	while ((*a)->i > ((*a)->next->next->i))
		rrotate(a, 'a');
	solve_2(a);
	if ((*a)->next->i > ((*a)->next->next->i))
	{
		rrotate(a, 'a');
		swap(a, 'a');
	}
}

void	solve_4(t_list	**a, t_list **b)
{
	t_list	*iter;
	int		count;

	iter = *a;
	count = iter->i;
	while (iter != 0)
	{
		if (count > iter->i)
			count = iter->i;
		iter = iter->next;
	}
	if ((*a)->next->i == count)
		swap(a, 'a');
	else
		while ((*a)->i != count)
			rrotate(a, 'a');
	push_stack(a, b, 'b');
	solve_3(a);
	push_stack(b, a, 'a');
}

void	solve_5(t_list **a, t_list **b)
{
	t_list	*iter;
	int		count;

	iter = *a;
	count = iter->i;
	while (iter != 0)
	{
		if (count > iter->i)
			count = iter->i;
		iter = iter->next;
	}
	if ((*a)->next->i == count)
		swap(a, 'a');
	else if ((*a)->next->next->i == count)
		while ((*a)->i != count)
			rotate(a, 'a');
	else
		while ((*a)->i != count)
			rrotate(a, 'a');
	push_stack(a, b, 'b');
	solve_4(a, b);
	push_stack(b, a, 'a');
}

void	five_or_less(t_list	**a, t_list **b)
{
	int	n;

	n = count_stack(*a);
	if (n == 2)
		solve_2(a);
	else if (n == 3)
		solve_3(a);
	else if (n == 4)
		solve_4(a, b);
	else if (n == 5)
		solve_5(a, b);
}
