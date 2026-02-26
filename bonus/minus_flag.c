/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:38 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 22:22:14 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	minus_flag(int *i, const char *str, va_list list)
{
	int				count;
	int				n;
	int				printed;

	count = 0;
	if (str[*i + 1] == '-')
	{
		*i += 2;
		n = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		printed = ft_check_case(str, list, *i);
		count = printed;
		while (count < n)
		{
			write(1, " ", 1);
			count++;
		}
		(*i)++;
	}
	return (count);
}
