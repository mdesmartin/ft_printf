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

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_arg(va_list arg, const char *txt, int len)
{
	char *s;
	int	i;

	if (*txt == 'c')
//		return (write(1, (const void *)va_arg(arg, char *), 1)); // marche pas dommache ct stylai
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	else if (*txt == '%')
		return (write(1, "%", 1));
	else if (*txt == 's')
	{
		s = va_arg(arg, char *);
		return (write(1, s, ft_strlen(s)));
	}
	else if (*txt == 'd' || *txt == 'i')
	{
		i = va_arg(arg, int);
		return (ft_put_n_count(i));
	}
	else if (*txt == 'p')
	{
//	unsigned long a recup et scocker,
//	puis 0x et convertir en hexa le unsigned long et [utnbr]
	}
	if (text == 'u')
		ft_putstr((unsigned int)ft_atoi(x));
	if (text == 'x')
		ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'x')));
	if (text == 'X')
		ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'X')));
	else
		return (len);
	return (len);
}

int	ft_printf(const char *txt, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, txt);
	while (*txt)
	{
		if (*txt == '%')
		{
			len += ft_arg(arg, txt + 1, len);
			txt += 2;
		}
		else
		{
			len += write(1, txt, 1);
			txt++;
		}
	}
	va_end(arg);
	return (len);
}

int	main()
{
	int t = 5;
	int *pt = &t;

	int a = ft_printf("f : je suis un %i des iles\n", 789);
	int b = printf("p : je suis un %i des iles\n", 789);

	printf("ma fonction renvoie : %d\nl'originale renvoie : %d", a, b);
}

// len of word, pourcentage a ecrire, 