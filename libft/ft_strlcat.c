/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:43:43 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/09 13:43:52 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_src;
	size_t	l_dst;

	l_dst = 0;
	l_src = ft_strlen(src);
	i = 0;
	if ((!dst || !src) && dstsize == 0)
		return (0);
	while (dst[l_dst] && l_dst < dstsize)
		l_dst++;
	while (src[i] && dstsize > i + l_dst + 1)
	{
		dst[i + l_dst] = src[i];
		i++;
	}
	if (l_dst < dstsize)
		dst[i + l_dst] = '\0';
	return (l_dst + l_src);
}
