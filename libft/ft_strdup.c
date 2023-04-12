/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:22:36 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/10 14:19:06 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	copy = malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
