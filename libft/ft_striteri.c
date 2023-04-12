/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:40:27 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/05 12:25:49 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (i < (unsigned int)ft_strlen(s))
		{
			f(i, &s[i]);
			i++;
		}
	}
}
