/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:44:19 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/14 14:44:20 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_goodsize(int size, int j, char *res, int num)
{
	char	*tab;

	if (num < 0)
		j = 1;
	if (size == 0)
	{
		tab = malloc(sizeof(char) * 2);
		if (!(tab))
			return (NULL);
		tab[0] = '0';
		tab[1] = '\0';
		return (tab);
	}
	else
		return (ft_substr(res, 0, size + j + 1));
}

static char	*ft_reverse(int size, int num, char *res, char *str)
{
	int	min;

	min = 0;
	size--;
	if (num < 0)
	{
		res[0] = '-';
		min++;
	}
	while (size >= 0)
	{
		res[min] = str[size];
		size--;
		min++;
	}
	res[min] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		str[14];
	char		res[14];
	int			size;
	int long	num;

	size = 0;
	num = n;
	if (num == 0)
		return (ft_goodsize(size, 0, str, num));
	if (num < 0)
		num = num * -1;
	while (num)
	{
		str[size] = (num % 10 + 48);
		num = num / 10;
		size++;
	}
	if (n < 0)
		num = -1;
	return (ft_goodsize(size, 0, ft_reverse(size, num, res, str), num));
}
