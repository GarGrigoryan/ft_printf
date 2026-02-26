/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:24:14 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 15:37:57 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_length(unsigned long n, char *base)
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

static int	ft_putptr(unsigned long p, char *base)
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

int	ptr_case(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		count += 5;
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_putptr(ptr, "0123456789abcdef");
	}
	return (count);
}
