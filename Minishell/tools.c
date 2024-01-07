/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:09:26 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/02 02:14:51 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char *input)
{
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.process_count = 0;
	tokenize(input);
	if (!lexer())
		return ;
	start_cmd();
	free_process();
}

void	ctrl_c(int sig)
{
	(void)sig;
	g_ms.exit_code = 1;
	g_ms.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{	
	if (!input)
	{
		printf("\nexit\n");
		exit(g_ms.exit_code);
	}
}

void	ctrl_bs(int sig)
{
	(void)sig;
	g_ms.ignore = TRUE;
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
