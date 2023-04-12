/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:32:46 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 09:32:48 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_action(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		exit(222);
	}
	else if (signum == SIGQUIT)
	{
		printf("Quit: 3\n");
		exit(223);
	}
}

void	signal_operator(t_system *my_env, int status)
{
	if (status == BASH_IN)
	{
		sigemptyset(&my_env->act.sa_mask);
		my_env->act.sa_flags = SA_RESTART;
		my_env->act.sa_handler = SIG_IGN;
		sigaction(SIGINT, &my_env->act, NULL);
	}
	else if (status == BASH_OPT)
	{
		sigemptyset(&my_env->act.sa_mask);
		my_env->act.sa_flags = SA_RESTART;
		my_env->act.sa_handler = child_action;
		sigemptyset(&my_env->quit.sa_mask);
		my_env->quit.sa_flags = SA_RESTART;
		my_env->quit.sa_handler = child_action;
		sigaction(SIGINT, &my_env->act, NULL);
	}
	else if (status == BASH_OUT)
	{
		sigemptyset(&my_env->act.sa_mask);
		my_env->act.sa_flags = SA_RESTART;
		my_env->act.sa_handler = sighandler;
		sigaction(SIGINT, &my_env->act, NULL);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, my_env->myshell_term);
	}
}
