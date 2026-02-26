/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:56:17 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 22:08:45 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(const char *str);
int	ft_putnbr_base(long long n, char *base);
int	ft_isvalid(const char *base);
int	ft_printf(const char *str, ...);
int	ptr_case(unsigned long ptr);
int	ft_atoi(const char *str);
int	minus_flag(int *i, const char *str, va_list list);
int	zero_flag(int *i, const char *str, va_list list);
int	ft_check_case(const char *str, va_list list, int i);
int	get_num_len(int n);

#endif
