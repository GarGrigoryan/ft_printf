/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:35:42 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 22:11:40 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_case(const char *str, va_list list, int i)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr_base(va_arg(list, int), "0123456789");
	if (str[i] == 'u')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	if (str[i] == 'x')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	if (str[i] == 'X')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (str[i] == 'c')
		count += ft_putchar(va_arg(list, int));
	if (str[i] == 's')
		count += ft_putstr(va_arg(list, char *));
	if (str[i] == '%')
		count += ft_putchar('%');
	if (str[i] == 'p')
	{
		ptr = va_arg(list, unsigned long);
		count += ptr_case(ptr);
	}
	return (count);
}

static int	ft_validate(const char *str, va_list list, int *i)
{
	int				count;

	count = 0;
	if (str[*i + 1] == '-')
		count += minus_flag(i, str, list);
	if (str[*i + 1] == '0')
		count += zero_flag(i, str, list);
	// if (str[i + 1] == '.')
	// if (str[i + 1] == '#')
	// if (str[i + 1] == ' ')
	// if (str[i + 1] == '+')
	return (count);
}

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
			count += ft_validate(str, list, &i);
		else
			count += ft_putchar(str[i++]);
	}
	va_end(list);
	return (count);
}

int	main()
{
	int a = ft_printf("%010d", 42);
	printf("%d", a);
	return 0;
}
