/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:04:16 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 23:26:57 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_echo(t_executor *exe, t_cmd_node *node)
{
	int	fd;
	int	i;

	fd = 1;
	i = 0;
	if (exe->out_fd > 0)
		fd = exe->out_fd;
	if (!ft_strncmp(node->cmd_arr[1], "-n", 3))
		i = 1;
	while (node->cmd_arr[++i])
	{
		ft_putstr_fd(node->cmd_arr[i], fd);
	}
	if (ft_strncmp(node->cmd_arr[1], "-n", 3))
	{
		// printf("hello\n");
		ft_putchar_fd('\n', fd);
	}	
	return (0);
}
