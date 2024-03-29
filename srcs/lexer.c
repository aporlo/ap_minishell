/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:56:01 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/10 14:18:20 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isquote(char ch)
{
	if (ch == 34 || ch == 39)
		return (0);
	return (1);
}

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\r'
		|| ch == '\n' || ch == '\v' || ch == '\f')
		return (0);
	return (1);
}

static void	add_cmd(t_stpar *stpar, t_data *data, int n)
{
	char	*substr;

	substr = NULL;
	if (n == 0)
		substr = ft_substr(data->cmd_str, stpar->l, (stpar->r - stpar->l));
	else
		substr = ft_substr(data->cmd_str, stpar->l, (stpar->r - stpar->l + 1));
	if (!(!ft_isquote(substr[0]) && ft_strlen(substr) == 2))
		ft_lstadd_back(&data->cmd_ll, ft_lstnew(ft_strdup(substr)));
	// printf("sub |%s|\n", substr);
	free(substr);
	if (n == 1)
		stpar->r++;
	stpar->l = stpar->r;
}

static int	check(t_data *data, t_stpar stpar)
{
	int		space;

	space = ft_isspace(data->cmd_str[stpar.r]);
	if ((space == 1 && ft_isquote(data->cmd_str[stpar.r]) == 1)
		&& stpar.r < stpar.len)
		return (1);
	return (0);
}

void	lexer(t_data *data, t_stpar stpar)
{
	int	i;
	// int n;

	i = 0;
	stpar.len = ft_strlen(data->cmd_str);
	while (stpar.r < stpar.len && stpar.l <= stpar.r)
	{
		if (ft_isspace(data->cmd_str[stpar.r]) == 0 && data->cmd_str[stpar.r + 1] != '-')
		{
			// printf("|%d| cmd1 %c\n", i, data->cmd_str[stpar.r]);
			if (data->cmd_str[stpar.r + 1] > ' ' && data->cmd_str[stpar.r + 1] != '\0' && i++)
			{
				// n = ;
				while (data->cmd_str[stpar.r] == ' ')
					stpar.r++;
				if (data->cmd_str[stpar.r] != '>' || data->cmd_str[stpar.r] != '<' || data->cmd_str[stpar.r] != '|')
				{
					data->cmd_str[stpar.r - 2] = ' ';
					add_cmd(&stpar, data, 1);
				}
				stpar.r++;
			}
			else
			{
				stpar.r++;
				stpar.l++;
			}
		}
		else if (ft_isquote(data->cmd_str[stpar.r]) == 0)
		{
			// printf("cmd2 %c\n", data->cmd_str[stpar.r]);
			stpar.quote = data->cmd_str[stpar.r];
			stpar.r++;
			while (data->cmd_str[stpar.r] != stpar.quote && stpar.r < stpar.len)
				stpar.r++;
			add_cmd(&stpar, data, 1);
		}
		else
		{
			while (data->cmd_str[stpar.l] == ' ')
				stpar.l++;
			if (data->cmd_str[stpar.r] == '|' || data->cmd_str[stpar.r] == '>'
				|| data->cmd_str[stpar.r] == '<')
				i = 0;
			stpar.r++;
			while (check(data, stpar) == 1)
				stpar.r++;
			// printf("cmd3 %s\n", &data->cmd_str[stpar.r]);
			add_cmd(&stpar, data, 0);
		}
		for (int j = stpar.r; data->cmd_str[j] != '\0'; j++)
		{
			if (data->cmd_str[j] != ' ')
			{
				if (data->cmd_str[j] == '<' || data->cmd_str[j] == '>' || data->cmd_str[j] == '|' || data->cmd_str[j] == '-') 
				{
					i = 0;
					break ;
				}	
			}	
		}
	}
	expander(&data->cmd_ll);
}
