/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:50:57 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/31 17:10:23 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	long			i;
	long long int	result;

	i = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\r' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			i = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = ((result * 10) + (*nptr - '0') * i);
		nptr++;
		if (result > 2147483646)
			error("Error\n");
		else if (result < -2147483647)
			error("Error\n");
	}
	return (result);
}

int	count_stack(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list	*next;

	next = malloc(sizeof(t_list));
	if (next == NULL)
		return (0);
	next->i = content;
	next->next = NULL;
	return (next);
}

t_list	*add_back(t_list *a, t_list *b)
{
	t_list	*iter;

	if (!a)
		a = b;
	else
	{
		iter = a;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = b;
	}
	return (a);
}

t_list	*add_stack(char **av, int ac)
{
	int		i;
	int		j;
	int		*num;
	t_list	*test;

	test = NULL;
	i = -1;
	num = check(av, ac);
	j = count_arg(av, ac);
	while (++i < j)
		test = add_back(test, ft_lstnew(num[i]));
	free(num);
	return (test);
}
