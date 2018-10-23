/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:46:19 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:46:22 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *str, char type)
{
	if (!str[0] && type == 'c')
		write(1, &str[0], 1);
	else
		ft_putstr(str);
}

int		ft_spacensymbl(char *symbol, char *str, int *modificators, int *format)
{
	int spaces;

	if (modificators != NULL)
		spaces = modificators[0] - ft_strlen(str);
	else
		spaces = 0;
	if (!ft_strlen(str) && !format[4] && modificators[1] != -1)
		spaces++;
	if (format[4] && !format[1])
		*symbol = '0';
	return (spaces);
}

int		ft_makestrwidth(char *str, int *modificators, int *format, char type)
{
	char	symbol;
	int		spaces;
	int		counter;

	symbol = ' ';
	spaces = ft_spacensymbl(&symbol, str, modificators, format);
	counter = 0;
	if (format[1])
	{
		ft_print(str, type);
		while (counter++ < spaces)
			ft_putchar(symbol);
	}
	else
	{
		while (counter++ < spaces)
			ft_putchar(symbol);
		ft_print(str, type);
	}
	if (type == 'c' && ft_strlen(str) == 0)
		return (counter);
	else
		return (counter + ft_strlen(str) - 1);
}
