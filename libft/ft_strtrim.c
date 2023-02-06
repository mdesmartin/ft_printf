/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:02:25 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/13 16:02:31 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int	ft_trim(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	if (set[0] == '\0')
		return (ft_substr(s1, start, ft_strlen(s1)));
	while (ft_trim(s1[start], set) == 1 && *s1)
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_strlen(s1);
	while (ft_trim(s1[end - 1], set) == 1)
		end--;
	return (ft_substr(s1, start, end - start));
}
