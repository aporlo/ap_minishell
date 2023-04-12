/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:45:58 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 01:46:03 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_export_str(char *str)
{
	int	i;
	int	equal;

	i = -1;
	equal = 0;
	while (str[++i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		if (str[i] == '=')
			equal++;
	}
	if (equal != 1)
		return (0);
	return (1);
}

static char	**add_env(char *newenv, char **arr)
{
	int		i;
	char	**ret;

	i = 0;
	while (arr[i])
		i++;
	ret = ft_calloc(sizeof(char *), i + 2);
	if (!ret)
		return (NULL);
	i = -1;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = ft_strdup(newenv);
	return (ret);
}

static void	print_env(t_system *env, int i)
{
	char	*var_name;

	while (env->env_cop[++i])
	{
		var_name = ft_strjoin("declare -x ", env->env_cop[i]);
		printf("%s\n", var_name);
		free(var_name);
	}
}

int	exe_export(t_cmd_node *node, t_system *env)
{
	int		i;

	i = -1;
	if (!node->cmd_arr[1])
		print_env(env, i);
	else
	{
		if (node->cmd_arr[2])
			printf("export only support 1 arguments\n");
		else if (!check_export_str(node->cmd_arr[1]))
			printf("improper string format\n");
		else
		{
			env->env_cop = add_env(node->cmd_arr[1], env->env_cop);
			if (!env->env_cop)
				return (1);
		}
	}
	return (0);
}
