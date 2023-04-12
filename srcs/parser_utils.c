/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:59:46 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/10 15:48:28 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ll_to_strarr(t_list *cmd_ll)
{
	char	**argv;
	int		i;
	t_list	*ptr;

	ptr = cmd_ll;
	i = 0;
	argv = ft_calloc (sizeof(char *), ft_lstsize(cmd_ll) + 1);
	if (!argv)
		return (NULL);
	while (ptr)
	{
		argv[i] = ft_strdup(ptr->token);
		ptr = ptr->next;
		i++;
	}
	return (argv);
}

t_list	*sub_linklist(t_list *left, t_list *right)
{
	t_list	*ret;

	ret = NULL;
	while (left && ft_strncmp(left->token, right->token,
			ft_strlen(right->token)))
	{
		ft_lstadd_back(&ret, ft_lstnew(left->token));
		left = left->next;
	}
	return (ret);
}

int	isredirection(t_list *ptr)
{
	if (!ft_strncmp(ptr->token, ">", 2)
		|| !ft_strncmp(ptr->token, "<", 2)
		|| !ft_strncmp(ptr->token, ">>", 3)
		|| !ft_strncmp(ptr->token, "<<", 3))
		return (1);
	return (0);
}

void	redirection_parse(t_list *ptr, t_cmd_table *cmd_table)
{
	if (ft_strncmp(ptr->token, "<", 2) == 0)
		cmd_table->infile = ft_strjoin("< :", ptr->next->token);
	if (ft_strncmp(ptr->token, ">", 2) == 0)
		cmd_table->outfile = ft_strjoin("> :", ptr->next->token);
	if (ft_strncmp(ptr->token, ">>", 3) == 0)
		cmd_table->outfile = ft_strjoin(">> :", ptr->next->token);
	if (ft_strncmp(ptr->token, "<<", 3) == 0)
		cmd_table->infile = ft_strjoin("<< :", ptr->next->token);
}
