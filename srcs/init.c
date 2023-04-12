/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:03:21 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 18:09:28 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static char	**copy_env(char **ev)
{
	char	**env;
	int		i;

	i = array_size(ev);
	env = ft_calloc(sizeof(char *), i + 1);
	if (!env)
		return (NULL);
	i = -1;
	while (ev[++i])
		env[i] = ft_strdup(ev[i]);
	return (env);
}

void	init(t_data *data, char **ev)
{
	data->cmd_str = NULL;
	data->cmd_ll = NULL;
	data->cmd_table = NULL;
	data->my_env.env_cop = copy_env(ev);
	data->my_env.env_path = ft_split(getenv("PATH"), ':');
	ft_bzero(data->my_env.dis_str, 499);
	ft_strlcat(data->my_env.dis_str, "Minishell@ ", 499);
	ft_strlcat(data->my_env.dis_str, curr_dir(), 499);
	ft_strlcat(data->my_env.dis_str, ": ", 499);
	data->my_env.act.sa_handler = sighandler;
	data->my_env.act.sa_flags = 0;
	sigemptyset(&data->my_env.act.sa_mask);
	sigaction (SIGINT, &data->my_env.act, NULL);
	data->my_env.quit.sa_handler = SIG_IGN;
}

void	init_terminal(t_system *env)
{
	env->myshell_term = malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, env->myshell_term);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, env->myshell_term);
}

void	init_stpar(t_stpar *stpar)
{
	stpar->len = 0;
	stpar->l = 0;
	stpar->r = 0;
}
