/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:31:27 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 15:40:09 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isvalid(const char *base)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_strlen(base);
	if (length < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_length(long long n, const char *base)
{
	int			length;
	int			count;
	long long	num;

	length = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		count++;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= length;
		count++;
	}
	return (count);
}

int	ft_putnbr_base(long long n, char *base)
{
	int	i;
	int	res;

	i = 0;
	res = ft_length(n, base);
	if (ft_isvalid(base))
	{
		while (base[i])
			i++;
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= i)
			ft_putnbr_base(n / i, base);
		write(1, &base[n % i], 1);
		return (res);
	}
	return (0);
}
