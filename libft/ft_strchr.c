/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:22:22 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/06 11:55:02 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cuc;
	size_t			i;
	size_t			slen;

	i = 0;
	slen = ft_strlen(s);
	cuc = (unsigned char)c;
	while (s[i] != cuc)
	{
		if (i == slen)
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
