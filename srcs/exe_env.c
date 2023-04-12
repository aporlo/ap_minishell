/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:06:28 by lsomrat           #+#    #+#             */
/*   Updated: 2023/04/09 09:06:42 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	int	index;

	index = 0;
	if (ac != 1 || av[1])
	{
		printf("This program don't support arguments\n exiting\n");
		return (1);
	}
	while (ev[index])
		printf("%s\n", ev[index++]);
	return (0);
}
