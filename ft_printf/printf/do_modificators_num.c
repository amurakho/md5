/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_modificators_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:34:51 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:34:53 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ifplusminus(char **str, int *format, int *counter, int *spaces)
{
	if (*str[0] == '-' && format[4])
	{
		*counter += 1;
		ft_putchar('-');
		*str += 1;
	}
	else if (format[0] && *str[0] != '-')
	{
		if (format[4])
		{
			*counter += 1;
			ft_putchar('+');
		}
		*spaces -= 1;
	}
}

void	ft_ifnzero(char **str, int *counter, int *format)
{
	if (*str[0] == '-')
	{
		ft_putchar('-');
		*str += 1;
		*counter += 1;
	}
	else if (format[0])
	{
		ft_putchar('+');
		*counter += 1;
	}
}

int		ft_ifnformat(char *str, int *format, int spaces, char symbol)
{
	int counter;

	counter = 0;
	if (format[2] && !format[0] && str[0] != '-')
	{
		ft_putchar(' ');
		counter++;
		spaces--;
	}
	if (format[4] || format[0])
		ft_ifplusminus(&str, format, &counter, &spaces);
	while (spaces-- > 0)
	{
		ft_putchar(symbol);
		counter++;
	}
	if (!format[4])
		ft_ifnzero(&str, &counter, format);
	ft_putstr(str);
	return (counter + ft_strlen(str));
}

int		ft_ifformat(char *str, int *format, int spaces, char symbol)
{
	int counter;

	counter = 0;
	if (format[0] && str[0] != '-')
	{
		counter++;
		ft_putchar('+');
		spaces--;
	}
	else if (format[2] && !format[0] && str[0] != '-' && spaces <= 0)
	{
		ft_putchar(' ');
		counter++;
	}
	ft_putstr(str);
	while (spaces > 0)
	{
		counter++;
		spaces--;
		ft_putchar(symbol);
	}
	return (counter + ft_strlen(str));
}

int		ft_ifnotint(char *str, int *format, char symbol, int spaces)
{
	int	counter;

	counter = 0;
	if (format[1])
	{
		ft_putstr(str);
		counter += ft_strlen(str);
		counter += ft_makewidthx(&str, format, symbol, spaces);
	}
	else
	{
		counter += ft_makewidthx(&str, format, symbol, spaces);
		ft_putstr(str);
		counter += ft_strlen(str);
	}
	return (counter);
}
