/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:39:36 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 18:08:39 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ltrim(const char *s, const char *set)
{
	size_t	start;

	start = 0;
	while (start < ft_strlen(s) && ft_strchr(set, *(s + start)))
		start++;
	return (start);
}

static size_t	rtrim(const char *s, const char *set, size_t n)
{
	size_t	end;

	end = ft_strlen(s);
	while (end > n && ft_strchr(set, *(s + end)))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	start = ltrim(s1, set);
	end = rtrim(s1, set, start);
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ptr)
		return (NULL);
	ret = ptr;
	while (start < end + 1)
		*ptr++ = s1[start++];
	*ptr = '\0';
	return (ret);
}
