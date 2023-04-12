/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:43:40 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/10 16:49:26 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_hdoc(char *infile, t_executor *exe)
{
	char	*str;
	char	*delim;

	delim = ft_strtrim(infile, "< :");
	while (1)
	{
		str = readline("heredoc> ");
		if (!ft_strncmp(str, delim, ft_strlen(delim)))
			break ;
		ft_putendl_fd(str, exe->in_fd);
	}
	close(exe->in_fd);
}

static void	stop_exe(t_cmd_table *cmdt, t_executor *exe)
{
	kill(exe->pid, 0);
	if (cmdt->infile)
	{
		if (!ft_strncmp(cmdt->infile, "<<", 2))
			unlink(".hdoc.tmp");
		close(exe->in_fd);
	}
	if (cmdt->outfile)
		close(exe->out_fd);
	if (exe->pipe)
		free(exe->pipe);
}

static int	exit_executor(t_data *data, t_executor *exe, int status)
{
	dup2(exe->old_stdin, STDIN_FILENO);
	dup2(exe->old_stdout, STDOUT_FILENO);
	stop_exe(data->cmd_table, exe);
	signal_operator(&data->my_env, BASH_OUT);
	return (status);
}

int	executor(t_data *data)
{
	t_executor	exe;

	if (!data->cmd_table)
		return (0);
	init_exe(&exe, data->cmd_table);
	signal_operator(&data->my_env, BASH_IN);
	if (is_buildins(data->cmd_table->cmds->cmd_arr[0]))
		buildins(data, &exe);
	else if (exe.pipe_no > 1)
	{
		if (pipe_executor(data, &exe) != 1)
			return (exit_executor(data, &exe, 0));
	}
	else
	{
		if (single_executor(data, &exe))
			return (exit_executor(data, &exe, 0));
	}
	return (exit_executor(data, &exe, 1));
}
