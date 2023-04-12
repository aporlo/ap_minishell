/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdnode_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:41:55 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 18:50:58 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_node	*newnode(t_list *temp)
{
	t_cmd_node	*new;

	new = malloc(sizeof(t_cmd_node));
	if (!new || !temp)
		return (NULL);
	new->cmd_arr = ll_to_strarr(temp);
	new->next = NULL;
	return (new);
}

void	node_addback(t_cmd_node **node, t_cmd_node *newn)
{
	t_cmd_node	*tmp_nd;

	if (!newn)
		return ;
	if (*node == NULL)
		*node = newn;
	else
	{
		tmp_nd = *node;
		while (tmp_nd->next)
			tmp_nd = tmp_nd->next;
		tmp_nd->next = newn;
	}
}

int	nodesize(t_cmd_node *cmds)
{
	t_cmd_node	*ptr;
	int			i;

	i = 0;
	ptr = cmds;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
