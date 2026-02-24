/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:35:42 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/24 16:55:03 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_validate(str, list, i);
			i += 2;
		}
		else
		{
			ft_putchar(str[i++]);
			count++;
		}
	}
	va_end(list);
	return (count);
}

int	ft_validate(const char *str, va_list list, int i)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr_base(va_arg(list, int), "0123456789");
	if (str[i + 1] == 'u')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	if (str[i + 1] == 'x')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	if (str[i + 1] == 'X')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (str[i + 1] == 'c')
		count += ft_putchar(va_arg(list, int));
	if (str[i + 1] == 's')
		count += ft_putstr(va_arg(list, char *));
	if (str[i + 1] == '%')
		count += ft_putchar('%');
	else if (str[i + 1] == 'p')
	{
		ptr = va_arg(list, unsigned long);
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
	}
	return (count);
}

// int	main()
// {
// 	// int a = 5;
// 	// int *b = &a;
// 	// ft_printf("%p", b);
// 	int c = printf("%p", 0);
// 	printf("%d", c);
// 	return 0;
// }
