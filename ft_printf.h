/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:32:17 by mvogel            #+#    #+#             */
/*   Updated: 2022/12/01 12:32:20 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *txt, ...);
int		flag_type(va_list arg, const char *txt);
int		print_pt(unsigned long x);
int		print_hexa(unsigned int x, int upper);
int		print_nbr(int i);
int		print_unsigned(unsigned int u);
void	ft_putlongnbr_fd(long n, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

#endif
