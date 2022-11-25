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

#include <stdarg.h>

int    ft_printf(const char *text, ...)
{
	int			nb_arg;
	va_list		arg;

	va_start (arg, text);
	// if (!arg)
	// 	return (NULL);
	while (*text)
	{
		while (text != '%')
		{
			ft_putchar(*text);
			text++;
		}
		flagtype((text + 1), va_arg(arg, int));
		nb_arg--;
	}
	text += 2;
	va_end(arg);
//	return (quel int ???sortie derreur ?);
}

static char	*ft_flag_type(char *text, int x)
{
	if (text == 'c')
		ft_putchar(x);
	if (text == 's')
		ft_putstr(x);
	if (text == '%')
		ft_putchar('%');
	if (text == 'd' || text == 'i')
		ft_putstr(ft_atoi(x));
	if (text == 'u')
		ft_putstr((unsigned int)ft_atoi(x));
	// if (text == 'x')
	// 	ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'x')));
	// if (text == 'X')
	// 	ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'X')));
}

// char	*ft_convert_hexa(va_arg(arg, int), char a)
// {}

int	main()
{}

reste a tester la fonction, changer int pour char ou *char, puis enfin hexa, proto, makefile, 