/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:06:00 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/08 17:41:08 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*rc;
	char		*st;

	rc = src;
	st = dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		*st = *rc;
		st++;
		rc++;
		n--;
	}
	return (dst);
}
