/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:35:42 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/20 16:24:52 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_validate(str, &i);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_validate(const char *str, int *i)
{
	if (str[*i + 1] == 'c')
		return ;
}

// "" 2 case
// 1) % ka
//		pti stugenq ira hajord chary kara ylni cspdiuxX% srancic kamayakan meky yete che return -1 u error
// 2) % chka
//		tupy tpum enq


