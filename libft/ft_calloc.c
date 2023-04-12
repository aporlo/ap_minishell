/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:20 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/05 23:39:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*alme;
	size_t	i;

	i = 0;
	alme = malloc (count * size);
	if (!alme)
		return (NULL);
	while (i < count * size)
	{
		alme[i] = 0;
		i++;
	}
	return (alme);
}
