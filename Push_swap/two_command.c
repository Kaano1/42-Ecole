/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:32:56 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/31 17:32:57 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap2swap(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	s_write("ss\n", 1);
}

void	rotate2rot(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	s_write("rr\n", 1);
}

void	rev2rot(t_list **a, t_list **b)
{
	rrotate(a, 0);
	rrotate(b, 0);
	s_write("rrr\n", 1);
}
