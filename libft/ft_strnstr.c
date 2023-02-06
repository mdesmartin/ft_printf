/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:11 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/09 16:58:13 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;

	i = 0;
	if (!(needle[i]))
		return ((char *)haystack);
	if (!len)
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0' && i < len)
				return ((char *)&haystack[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
