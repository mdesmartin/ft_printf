/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:51:40 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/21 15:51:41 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nxt;

	if (!del || !lst || !*lst)
		return ;
	if (lst)
	{
		current = *lst;
		while (current)
		{
			nxt = current->next;
			ft_lstdelone(current, (del));
			current = nxt;
		}
		*lst = NULL;
	}
}
