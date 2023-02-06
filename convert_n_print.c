/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:35:26 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/06 17:00:00 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int x, int upper)
{
	int		i;
	int		len;
	int		res[99];
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	if (upper == 1)
		hexa = "0123456789ABCDEF";
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	len = i + 1;
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
	return (len);
}

int	print_pt(unsigned long x)
{
	int		i;
	int		len;
	int		res[99];
	char	*hexa;

	write (1, "0x", 2);
	i = 0;
	hexa = "0123456789abcdef";
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	len = i + 3;
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
	return (len);
}

int	print_nbr(int i)
{
	size_t	len;

	len = 1;
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	ft_putlongnbr_fd(i, 1);
	if (i < 0)
	{
		len = 2;
		i = -i;
	}
	while (i >= 10)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

int	print_unsigned(int u)
{
	int	len;

	len = 1;
	if (u < 0)
		u = u % 4294967295 + 1;
	ft_putlongnbr_fd(u, 1);
	while (u >= 10)
	{
		u = u / 10;
		len++;
	}
	return (len);
}

void	ft_putlongnbr_fd(long n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n >= 10)
	{
		ft_putlongnbr_fd(n / 10, fd);
		ft_putlongnbr_fd(n % 10, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlongnbr_fd(-n, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
