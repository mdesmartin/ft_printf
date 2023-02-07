/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:32:17 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/07 13:57:55 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *txt, ...);
int		flag_type(va_list arg, const char *txt);
int		print_pt(unsigned long x);
int		print_hexa(unsigned int x, int upper);
int		print_nbr(int i);
int		print_unsigned(int u);
void	ft_putlongnbr_fd(long n, int fd);

#endif
