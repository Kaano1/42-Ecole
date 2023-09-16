/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:33:18 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/09 11:12:33 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
t_list	*add_back(t_list *a, t_list *b);
t_list	*add_stack(char **av, int ac);

int		count_stack(t_list *lst);
int		*check(char **av, int ac);
void	five_or_less(t_list	**a, t_list **b);
int		ft_atoi(const char *nptr);

void	push_stack(t_list **push, t_list **stack, char c);
void	rotate(t_list **lst, char c);
void	rrotate(t_list **lst, char s);
void	swap(t_list **lst, char c);
void	swap2swap(t_list **a, t_list **b);
void	rotate2rot(t_list **a, t_list **b);
void	rev2rot(t_list **a, t_list **b);
void	error(char *str);

void	solve_2(t_list **a);
void	solve_3(t_list **a);
void	solve_4(t_list	**a, t_list **b);
void	solve_5(t_list **a, t_list **b);

void	s_write(char *str, int mod);
void	check_dif_char(char **av, int ac);
void	radix(t_list **a, t_list **b, int ac);
int		*fix_num2(int *num, int *num2, int len);
void	pree(t_list *a, t_list *b);

void	check_arg(char *str);
int		ft_strlen(char *str);
int		count_arg(char **av, int ac);
void	same_value(int *num, int count);
int		*fix_num(int *num, int len);
int		calculate_num(char *str);
int		ft_atoi_arg(char *str, int start);
int		count_arg(char **av, int ac);
int		*add(int *num, int len);
#endif