/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:16:30 by mvogel            #+#    #+#             */
/*   Updated: 2022/11/25 09:16:31 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_type(va_list arg, const char *txt)
{
	char	*s;

	if (*txt == 'c')
		return (1 + ft_putchar_fd(va_arg(arg, int), 1));
	else if (*txt == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			return (write(1, "(null)", 6));
		return (write(1, s, ft_strlen(s)));
	}
	else if (*txt == 'p')
		return (print_pt(va_arg(arg, unsigned long)));
	else if (*txt == 'd' || *txt == 'i')
		return (print_nbr(va_arg(arg, int)));
	else if (*txt == 'u')
		return (print_unsigned(va_arg(arg, long int)));
	else if (*txt == 'x')
		return (print_hexa(va_arg(arg, long int), 0));
	else if (*txt == 'X')
		return (print_hexa(va_arg(arg, long int), 1));
	else if (*txt == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &*txt, 1));
}

int	ft_printf(const char *txt, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, txt);
	if (write(1, 0, 0) != 0)
		return (-1);
	while (*txt)
	{
		if (*txt == '%')
		{
			txt++;
			if (*txt != '\0')
				len += flag_type(arg, txt);
		}
		else
			len += write(1, txt, 1);
		if (*txt)
			txt++;
	}
	va_end(arg);
	return (len);
}
