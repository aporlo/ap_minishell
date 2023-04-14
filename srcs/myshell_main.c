/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:08:07 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/10 16:23:31 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*curr_dir(void)
{
	char	pwd[1000];
	char	*ret;

	if (!getcwd(pwd, 999))
		return (NULL);
	ret = ft_strrchr(pwd, '/', 1);
	return (ret);
}

void	exit_shell(t_data *data, int s)
{
	if (s != 0)
		perror("Myshell");
	if (data->cmd_table)
		free_cmdtable(data);
	if (data->cmd_ll)
		ft_lstclear(&data->cmd_ll, &free_token);
	free(data->my_env.myshell_term);
	free_arr(data->my_env.env_cop);
	free_arr(data->my_env.env_path);
	rl_clear_history();
	printf("exit\n");
	exit(s);
}

int	main(int ac, char **av, char **ev)
{
	t_data	data;
	t_stpar	stpar;

	if (ac != 1 || av[1])
	{
		printf("Myshell supposed to run without args\n");
		exit(1);
	}
	init(&data, ev);
	init_terminal(&data.my_env);
	init_stpar(&stpar);
	while (1)
	{
		data.cmd_str = readline(data.my_env.dis_str);
		if (data.cmd_str == NULL)
			break ;
		if (ft_strlen(data.cmd_str) == 0)
		{
			free(data.cmd_str);
			continue ;
		}
		add_history(data.cmd_str);
		lexer(&data, stpar);
		data.cmd_table = parser(data.cmd_ll);
			// for (t_cmd_node *n = data.cmd_table[0].cmds; n != NULL;)
			// 	{
			// 		for (int k = 0; n->cmd_arr[k] != NULL; k++)
			// 		{
					
			// 			printf("|%d|-|%s|\n", k, n->cmd_arr[k]);
			// 		}
			// 		// printf("|%p|\n", n->next);
			// 		n = n->next;
			// 	}
		// printf("out %s\n", data.cmd_table->outfile);
		executor(&data);
		free(data.cmd_str);
		free_cmdtable(&data);
		ft_lstclear(&data.cmd_ll, &free_token);
	}
	exit_shell(&data, 0);
	return (0);
}
