/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:43:57 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/10 16:47:41 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmdtable(t_data *data)
{
	node_clear(&data->cmd_table->cmds);
	if (data->cmd_table->infile)
		free(data->cmd_table->infile);
	if (data->cmd_table->outfile)
		free(data->cmd_table->outfile);
	free(data->cmd_table);
	data->cmd_table = NULL;
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr[0])
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}	
	free(arr);
}

void	free_temp(t_list *temp)
{
	t_list *list;

	list = temp;
	while (list != NULL)
	{
		free(list->token);
		list = list->next;
	}
	free(list);
}

void	free_token(void *content)
{
	free(content);
}

void	node_clear(t_cmd_node **node)
{
	t_cmd_node	*prev;

	if (!node)
		return ;
	prev = *node;
	while (*node)
	{
		*node = (*node)->next;
		free_arr(prev->cmd_arr);
		free(prev);
		prev = *node;
	}
}
