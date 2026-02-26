/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:56:17 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 15:38:10 by gargrigo         ###   ########.fr       */
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

#endif
