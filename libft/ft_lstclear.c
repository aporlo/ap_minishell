/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:47:31 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/10 16:50:34 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	check_empty_token(void *token)
{
	char	*cast;

	cast = (char *) token;
	if (!ft_strncmp(cast, "", 1) || !ft_isprint(cast[0]))
		return (0);
	return (1);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	if (lst && del)
	{
		prev = *lst;
		while (*lst)
		{
			*lst = (*lst)->next;
			del(prev);
			prev = *lst;
		}
		*lst = 0;
	}
}
