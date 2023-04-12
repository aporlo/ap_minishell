/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:20:34 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/05 11:51:15 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*uc_dst;
	char	*uc_src;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	uc_dst = (char *)dst;
	uc_src = (char *)src;
	while (i++ < n)
		*uc_dst++ = *uc_src++;
	return (dst);
}
