/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:20:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/02/28 22:20:21 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1uc;
	unsigned char	*s2uc;
	size_t			i;

	i = 0;
	s1uc = (unsigned char *)s1;
	s2uc = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1uc[i] != s2uc[i])
			return (s1uc[i] - s2uc[i]);
		i++;
	}
	return (0);
}
