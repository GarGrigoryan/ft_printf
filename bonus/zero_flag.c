/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:47:44 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/26 22:23:12 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zero_flag(int *i, const char *str, va_list list)
{
	int				count;
	int				n;
	int				printed;
	int				val;
	va_list			copy;

	va_copy(copy, list);
	count = 0;
	val = va_arg(copy, int);
	if (str[*i + 1] == '0')
	{
		*i += 2;
		n = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		while (count++ < n - get_num_len(val))
			write(1, "0", 1);
		ft_check_case(str, list, *i);
		(*i)++;
	}
	va_end(copy);
	return (count + get_num_len(val));
}
