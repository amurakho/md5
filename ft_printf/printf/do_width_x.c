/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_width_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:33:15 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:33:17 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_makewidthx(char **str, int *format, char symbol, int spaces)
{
	int		counter;
	int		size;
	char	*c_str;

	c_str = *str;
	size = 0;
	counter = 0;
	if (format[4] && format[3] && !format[1]
		&& (c_str[1] == 'x' || c_str[1] == 'X'))
	{
		while (counter != 2)
		{
			ft_putchar(**str);
			*str += 1;
			counter++;
			size++;
		}
	}
	while (spaces > 0)
	{
		ft_putchar(symbol);
		spaces--;
		size++;
	}
	return (size);
}
