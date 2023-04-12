/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:19 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 18:08:53 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	char	*ret;
	size_t	bytes;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	bytes = len;
	if (len >= ft_strlen(s))
		bytes = (ft_strlen(s) - (size_t)start);
	copy = malloc(sizeof(char) * (bytes + 1));
	if (!copy)
		return (NULL);
	ret = copy;
	while (s[start] && len--)
		*copy++ = s[start++];
	*copy = '\0';
	return (ret);
}
