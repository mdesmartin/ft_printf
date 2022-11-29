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

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef	struct s_sc
{
	int	len;
	int	widht;
}				t_sc;

// char	*ft_strchr(const char *txt)
// {
// 	while (*txt)
// 	{
// 		if (*txt == '%')
// 			return ((char *)txt);
// 		txt++;
// 	}
// 	if (!txt)
// 		return ((char *)txt);
// 	return (NULL);
// }

int	ft_intlen(int nb, char c)
{
	int	i = 0;
	int number;
	int neg;

	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	if (c == 'd')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	if (c == 'x')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}

void	ft_printhexa(unsigned int x, int upper)
{
	char *hexa = "0123456789abcdef";
	int	res[100];
	int i = 0;

	if (upper == 1)
		hexa = "0123456789ABCDEF";

	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
}

const char	*ft_search_arg(va_list arg, const char *txt, t_sc *sc)
{
	int		d;
	char	*s;
	unsigned int x;

	if (*txt == 'd' || *txt == 'i')
	{
		d = va_arg(arg, int); //traduit larg rcu en int
		ft_putnbr_fd(d, 1);
		sc->len += ft_intlen(d, *txt);
	}
	else if (*txt == 's' || *txt == 'c')
	{
		s = va_arg(arg, char *); //traduit larg rcu en char*
		if (!s)
		{
			write(1, "(null)", 6);
			sc->len += 6;
		}
		else
		{
			ft_putstr(s);
			sc->len += ft_strlen(s);
		}
	}
	else if (*txt == 'x') // p ??
	{
		x = va_arg(arg, unsigned int);
		ft_printhexa((unsigned long)x, 0);
		sc->len += ft_intlen((int)x, * txt);
	}
	else if (*txt == 'X')
	{
		x = va_arg(arg, unsigned int);
		ft_printhexa((unsigned long)x, 1);
		sc->len += ft_intlen((int)x, * txt);
	}
	else if (*txt == '%')
	{
		write(1, '%', 1);
		sc->len += 1;
	}
	else if (*txt == 'u')
	{
		x = va_arg(arg, unsigned int);
		ft_putnbr_fd(x, 1);
		sc->len += ft_intlen(x, *txt);
	} // p ?
	else
		return (NULL);
	txt++;
	return (txt);
}

const char	*ft_read_text(t_sc *sc, const char *txt)
{
	char *next;

	next = ft_strchr(txt, '%');
	if (next)
		sc->widht = next - txt;
	else
		sc->widht = ft_strlen(txt);
	write (1, txt, sc->widht);
	sc->len += sc->widht;
	while (*txt && *txt != '%')
		txt++;
	return (txt);
}

int    ft_printf(const char *txt, ...)
{
	va_list	arg;
	va_start(arg, txt);
	va_list	start;
	sc.len = 0;
	sc.widht = 0;

	while (*txt)
	{
		if (*txt == '%')
			txt = ft_search_arg(arg, txt + 1, &sc);
		else
			txt = ft_read_text(&sc, txt);
		if (!txt)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}

int	main()
{
	int a = ft_printf("je suis un &s", "poisson");
	int b = printf("je suis un &s", "poisson");

	printf("\n ma fonction renvoie : %d\nl'originale renvoie : %d", a, b);
}

// ///

// int    ft_printf(const char *text, ...)
// {
// 	int			nb_arg;
// 	va_list		arg;

// 	va_start (arg, text);
// 	// if (!arg)
// 	// 	return (NULL);
// 	while (*text)
// 	{
// 		while (text != '%')
// 		{
// 			ft_putchar_fd(*text);
// 			text++;
// 		}
// 		flagtype((text + 1), va_arg(arg, int));
// 		nb_arg--;
// 	}
// 	text += 2;
// 	va_end(arg);
// //	return (quel int ???sortie derreur ?);
// }

// static char	*ft_flag_type(char *text, int x)
// {
// 	if (text == 'c')
// 		ft_putchar_fd(x);
// 	if (text == 's')
// 		ft_putstr(x);
// 	if (text == '%')
// 		ft_putchar_fd('%');
// 	if (text == 'd' || text == 'i')
// 		ft_putstr(ft_atoi(x));
// 	if (text == 'u')
// 		ft_putstr((unsigned int)ft_atoi(x));
// 	// if (text == 'x')
// 	// 	ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'x')));
// 	// if (text == 'X')
// 	// 	ft_putstr((unsigned int)ft_atoi(ft_convert_hexa(x, 'X')));
// }

// // char	*ft_convert_hexa(va_arg(arg, int), char a)
// // {}

// int	main()
// {}

// reste a tester la fonction, changer int pour char ou *char, puis enfin hexa, proto, makefile, 