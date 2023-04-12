/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:06:33 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 16:06:34 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_env(t_system *env, t_cmd_node *node)
{
	int	i;

	i = -1;
	if (node->cmd_arr[1])
	{
		printf("minishell env don't support optional cmds\n");
		return (0);
	}
	while (env->env_cop[++i])
	{
		if (!printf("%s\n", env->env_cop[i]))
			return (1);
	}
	return (0);
}
