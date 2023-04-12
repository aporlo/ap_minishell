/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:12:33 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 16:12:34 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_node(char *str)
{
	if (str[0] == '-')
	{
		printf("unset don't support optional command\n");
		return (0);
	}
	return (1);
}

static int	get_start(char *torem, char **arr, int size)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (arr[i])
	{
		if (i == size)
			return (0);
		if (!ft_strncmp(arr[i], torem, ft_strlen(torem)))
		{
			start = i;
			free(arr[i]);
			break ;
		}
		i++;
	}
	while (arr[start + 1])
	{
		arr[start] = ft_strdup(arr[start + 1]);
		start++;
	}
	return (start);
}

static void	remove_char_arr(char *torem, char **arr)
{
	int	size;
	int	start;

	size = 0;
	start = 0;
	while (arr[size])
		size++;
	start = get_start(torem, arr, size);
	if (start > 0)
		arr[start] = 0;
	return ;
}

int	exe_unset(t_cmd_node *node, t_system *env)
{
	int	i;

	i = 1;
	while (node->cmd_arr[i])
	{
		if (!validate_node(node->cmd_arr[i]))
			break ;
		remove_char_arr(node->cmd_arr[i], env->env_cop);
		i++;
	}
	return (0);
}
