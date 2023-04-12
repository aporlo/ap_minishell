/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:24:35 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/03 14:58:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c, int skip)
{
	unsigned char	cuc;
	size_t			i;

	i = ft_strlen(s);
	cuc = (unsigned char) c;
	while (s[i] != cuc)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	if (skip == 0)
		return ((char *)s + i);
	else
		return ((char *)s + i + 1);
}
