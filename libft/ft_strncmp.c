/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:24:03 by pingpanu          #+#    #+#             */
/*   Updated: 2023/03/25 15:14:00 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-42);
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
	{
		if (i == (n - 1))
			break ;
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
