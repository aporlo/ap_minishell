/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:24:15 by pingpanu          #+#    #+#             */
/*   Updated: 2022/02/28 22:24:17 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *) haystack);
	while (*haystack && n <= len--)
	{
		if (!ft_memcmp(haystack, needle, n))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
