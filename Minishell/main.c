/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:46:45 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/02 02:21:42 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_ms;

void	init_app(char **env)
{
	g_ms.exit_code = 0;
	g_ms.parent_pid = getpid();
	g_ms.paths = NULL;
	set_env(env);
	set_paths();
}

void	main_continue(char *input)
{
	if (ft_pipecheck(input))
		init_shell(input);
	add_history(input);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	init_app(env);
	while (ac && av)
	{
		g_ms.ignore = FALSE;
		signal(SIGQUIT, &ctrl_bs);
		signal(SIGINT, &ctrl_c);
		write(1, "\033[32m", 5);
		input = readline("Minishell >>> ");
		write(1, "\033[0m", 4);
		ctrl_d(input);
		if (g_ms.ignore)
		{
			free(input);
			input = malloc(1);
		}
		else if (*input && g_ms.ignore == FALSE)
			main_continue(input);
		free(input);
	}
	exit(g_ms.exit_code);
}
