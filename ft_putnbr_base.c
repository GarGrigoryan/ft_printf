/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:31:27 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/20 17:06:47 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_isvalid(const char *base, int length)
{
	int	i;
	int	j;

	i = 0;
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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_length(long long n, const char *base)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(base);
	if (n <= 9 && n >= 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n /= length;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long long n, char *base)
{
	int	i;
	int	res;

	i = 0;
	res = ft_length(n, base);
	if (ft_isvalid(base, res))
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

int main()
{
	printf("%d", ft_putnbr_base(8, "01"));
	return 0;
}
