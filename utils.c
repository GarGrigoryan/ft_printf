/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:55:01 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/24 16:38:52 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_ptr_length(unsigned long n, char *base)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (n >= 0 && n <= 9)
		return (1);
	while (n)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long p, char *base)
{
	int	i;
	int	res;

	i = 0;
	res = ft_ptr_length(p, base);
	if (ft_isvalid(base))
	{
		while (base[i])
			i++;
		if (p >= (unsigned int)i)
			ft_putnbr_base(p / i, base);
		ft_putchar(base[p % i]);
		return (res);
	}
	return (0);
}
