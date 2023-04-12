/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:24:40 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 18:07:04 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	no_of_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*str_start(const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[j] == c && s[j + 1] == c)
		j++;
	while (s[j])
	{
		if (i == 0 && s[j] != c && j == 0)
			return ((char *)&s[j]);
		if ((s[j] == c && s[j + 1] != c))
			return ((char *)&s[j + 1]);
		j++;
	}
	return ((char *)s);
}

static	char	*get_str(const char *cur, char c)
{
	int		len;
	char	*ret;

	len = 0;
	while (cur[len] && cur[len] != c)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	cur += ft_strlcpy(ret, cur, (len + 1));
	return (ret);
}

char	**ft_error(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*cur;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = no_of_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = 0;
	cur = (char *)s;
	i = -1;
	while (++i < words)
	{
		cur = str_start(cur, c, i);
		split[i] = get_str(cur, c);
		if (!split[i])
			return (ft_error(split));
	}
	return (split);
}
