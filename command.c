/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:13 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/31 17:10:14 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list	*iter;

	if (count_stack(*lst) > 1)
	{
		iter = *lst;
		*lst = (*lst)->next;
		iter->next = (*lst)->next;
		(*lst)->next = iter;
		if (c == 'a')
			s_write("sa\n", 1);
		else if (c == 'b')
			s_write("sb\n", 1);
	}
}

void	push_stack(t_list **push, t_list **stack, char c)
{
	t_list	*iter;

	iter = *push;
	*push = (*push)->next;
	iter->next = *stack;
	*stack = iter;
	if (c == 'a')
		s_write("pa\n", 1);
	else if (c == 'b')
		s_write("pb\n", 1);
}

void	rotate(t_list **lst, char ch)
{
	t_list	*iter;
	t_list	*c;

	iter = *lst;
	c = iter;
	*lst = (*lst)->next;
	while (c->next != 0)
		c = c->next;
	c->next = iter;
	iter->next = 0;
	if (ch == 'a')
		s_write("ra\n", 1);
	else if (ch == 'b')
		s_write("rb\n", 1);
}

void	rrotate(t_list **lst, char s)
{
	t_list	*c;

	if (count_stack(*lst) > 1)
	{
		c = *lst;
		while (c != 0 && c->next->next != 0)
			c = c->next;
		c->next->next = *lst;
		*lst = c->next;
		c->next = 0;
		if (s == 'a')
			s_write("rra\n", 1);
		else if (s == 'b')
			s_write("rrb\n", 1);
	}
}
