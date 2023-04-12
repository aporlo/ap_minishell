/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:32:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/01 12:02:02 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n, int pos)
{
	int		len;

	len = 0;
	if (pos == -1 || n == 0)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_strnum(char *str, unsigned int nbr, int pos, int l)
{
	str[l] = '\0';
	l--;
	while (l >= 0)
	{
		str[l] = (nbr % 10) + '0';
		nbr /= 10;
		if (l == 0 && pos == -1)
			str[l] = '-';
		l--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*num;
	char			*out;
	int				len;
	int				pos;

	nbr = n;
	pos = 1;
	if (n < 0)
	{
		pos = -1;
		nbr = n * -1;
	}
	len = ft_len(nbr, pos);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	out = num;
	num = ft_strnum(num, nbr, pos, len);
	return (out);
}
