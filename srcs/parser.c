/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:46:53 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/10 16:45:57 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd_table	*start_parse(void)
{
	t_cmd_table	*ret;

	ret = malloc(sizeof(t_cmd_table));
	if (!ret)
		return (NULL);
	ret->cmds = NULL;
	ret->infile = NULL;
	ret->outfile = NULL;
	return (ret);
}

t_cmd_table	*parser(t_list *cmd_ll)
{
	t_cmd_table	*cmd_table;
	t_list		*left;
	t_list		*right;
	t_list		*temp;

	cmd_table = start_parse();
	left = cmd_ll;
	right = cmd_ll;
	while (right)
	{
		if (isredirection(right) || !ft_strncmp(right->token, "|", 2))
		{
			redirection_parse(right, cmd_table);
			temp = sub_linklist(left, right);
			node_addback(&cmd_table->cmds, newnode(temp));
			free_temp(temp);
			left = right->next;
			if (isredirection(right))
				left = left->next;
		}
		if (right->next == NULL)
			node_addback(&cmd_table->cmds, newnode(left));
		right = right->next;
	}
	return (cmd_table);
}
