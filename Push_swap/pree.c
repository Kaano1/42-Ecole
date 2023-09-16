/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:29 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/31 17:10:55 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pree(t_list *a, t_list *b)
{
	while (a != 0)
	{
		push_stack(&a, &b, 0);
		free(b);
	}
	free(a);
}