/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:56:17 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/24 16:16:45 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long p, char *base);
int	ft_strlen(const char *str);
int	ft_putnbr_base(long long n, char *base);
int	ft_validate(const char *str, va_list list, int i);
int	ft_isvalid(const char *base);

#endif
