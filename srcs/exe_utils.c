/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:32:59 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 23:35:54 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path(char *cmd, char **env_path)
{
	char	*proto_ret;
	char	*ret;
	int		i;

	i = -1;
	while (env_path[++i])
	{
		proto_ret = ft_strjoin(env_path[i], "/");
		ret = ft_strjoin(proto_ret, cmd);
		free(proto_ret);
		if (access(ret, F_OK) == 0)
			return (ret);
		free(ret);
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	printf("%s: No such file or directory\n", cmd);
	return (NULL);
}

int	exec(t_system *env, t_cmd_node *node)
{
	char	*cmd_path;

	cmd_path = find_path(node->cmd_arr[0], env->env_path);
	if (execve(cmd_path, node->cmd_arr, NULL) < 0)
		return (0);
	return (1);
}

static void	init_inout(t_executor *exe, t_cmd_table *cmd_table)
{
	exe->in_fd = 0;
	exe->out_fd = 0;
	exe->old_stdin = dup(STDIN_FILENO);
	exe->old_stdout = dup(STDOUT_FILENO);
	if (!ft_strncmp(cmd_table->infile, "<", 1))
		exe->in_fd = open(ft_strtrim(cmd_table->infile, "< :"), O_RDONLY);
	else if (!ft_strncmp(cmd_table->infile, "<<", 2))
	{
		exe->in_fd = open(".hdoc.temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		write_hdoc(cmd_table->infile, exe);
		exe->in_fd = open(".hdoc.temp", O_RDONLY);
	}
	else if (!ft_strncmp(cmd_table->outfile, ">>", 2))
		exe->out_fd = open(ft_strtrim(cmd_table->outfile, "> :"),
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else if (!ft_strncmp(cmd_table->outfile, ">", 1))
		exe->out_fd = open(ft_strtrim(cmd_table->outfile, "> :"),
				O_CREAT | O_RDWR | O_TRUNC, 0644);
}

void	init_exe(t_executor *exe, t_cmd_table *cmd_table)
{
	int	pipe_ptr;

	pipe_ptr = -1;
	init_inout(exe, cmd_table);
	exe->node_ptr = -1;
	exe->nodesize = nodesize(cmd_table->cmds);
	exe->pipe_no = 2 * (exe->nodesize - 1);
	exe->pipe = NULL;
	if (exe->pipe_no > 0)
	{
		exe->pipe = (int *)malloc(sizeof(int) * exe->pipe_no);
		while (++pipe_ptr < exe->nodesize - 1)
			pipe(exe->pipe + 2 * pipe_ptr);
	}
}
