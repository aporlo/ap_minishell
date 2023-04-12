/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:09:02 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 16:09:03 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_pwd(t_cmd_node *node)
{
	char	*path;

	if (node->cmd_arr[1])
	{
		printf("minishell pwd don't support optional cmds\n");
		return (0);
	}
	path = ft_calloc(sizeof(char), 1000);
	if (getcwd(path, 999) != NULL)
		printf("%s\n", path);
	else
	{
		perror("pwd error");
		return (1);
	}
	return (0);
}
