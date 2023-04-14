/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:09:06 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 22:49:27 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_pipes(t_executor *exe)
{
	int	i;

	i = 0;
	while (i < exe->pipe_no)
	{
		close(exe->pipe[i]);
		i++;
	}
}

static void	dup_pipes(int to_in, int to_out)
{
	if (to_in > 0)
		dup2(to_in, STDIN_FILENO);
	if (to_out > 0)
		dup2(to_out, STDOUT_FILENO);
}

static int	child_processes(t_system *env, t_cmd_node *node, t_executor *exe)
{
	exe->node_ptr++;
	exe->pid = fork();
	if (exe->pid < 0)
		exit(0);
	else if (exe->pid == 0)
	{
		if (exe->node_ptr == 0)
			dup_pipes(exe->in_fd, exe->pipe[1]);
		else if (exe->node_ptr == exe->nodesize - 1)
			dup_pipes(exe->pipe[exe->node_ptr * 2 - 2], exe->out_fd);
		else
			dup_pipes(exe->pipe[exe->node_ptr * 2 - 2],
				exe->pipe[exe->node_ptr * 2 + 1]);
		close_pipes(exe);
		if (!ft_strncmp(node->cmd_arr[0], "echo", 5))
			exit(exe_echo(exe, node));
		if (exec(env, node))
			exit(0);
	}
	return (1);
}

int	pipe_executor(t_data *data, t_executor *exe)
{
	t_cmd_node	*cmd_ptr;
	t_cmd_table	*cmdt;

	cmdt = data->cmd_table;
	if ((exe->in_fd < 0 && cmdt->infile) || (exe->out_fd < 0 && cmdt->outfile))
	{
		perror("file not found\n");
		return (0);
	}
	cmd_ptr = data->cmd_table->cmds;
	tcsetattr(STDIN_FILENO, TCSANOW, data->my_env.myshell_term);
	signal_operator(&data->my_env, BASH_OPT);
	while (cmd_ptr)
	{
		if (!child_processes(&data->my_env, cmd_ptr, exe))
			exit(0);
		cmd_ptr = cmd_ptr->next;
	}
	close_pipes(exe);
	while (waitpid(-1, NULL, 0) != -1)
	{
	}
	tcsetattr(STDIN_FILENO, TCSANOW, data->my_env.myshell_term);
	return (1);
}
