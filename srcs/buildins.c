/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:02:39 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 23:26:35 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_buildins(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5) || !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4) || !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

int	buildins(t_data *data, t_executor *exe)
{
	t_cmd_node	*node;

	node = data->cmd_table->cmds;
	signal_operator(&data->my_env, BASH_OUT);
	if (!ft_strncmp(node->cmd_arr[0], "echo", 5))
		return (exe_echo(exe, node));
	if (!ft_strncmp(node->cmd_arr[0], "cd", 3))
		return (exe_cd(&data->my_env, node->cmd_arr[1]));
	if (!ft_strncmp(node->cmd_arr[0], "pwd", 4))
		return (exe_pwd(node));
	if (!ft_strncmp(node->cmd_arr[0], "export", 7))
		return (exe_export(node, &data->my_env));
	if (!ft_strncmp(node->cmd_arr[0], "unset", 6))
		return (exe_unset(node, &data->my_env));
	if (!ft_strncmp(node->cmd_arr[0], "env", 4))
		return (exe_env(&data->my_env, node));
	if (!ft_strncmp(node->cmd_arr[0], "exit", 5))
		exit_shell(data, 0);
	return (0);
}
