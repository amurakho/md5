/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makediff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:08:37 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 03:08:40 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_makediff(char type, int **full, va_list args)
{
	char	symbol;
	int		counter;

	counter = 0;
	if (type == 'c')
		type = va_arg(args, int);
	symbol = ' ';
	if (full[0][4] && !full[0][1])
		symbol = '0';
	full[1][0]--;
	if (full[0][1])
	{
		ft_putchar(type);
		while (counter++ < full[1][0])
			ft_putchar(symbol);
	}
	else
	{
		while (counter++ < full[1][0])
			ft_putchar(symbol);
		ft_putchar(type);
	}
	return (counter);
}
