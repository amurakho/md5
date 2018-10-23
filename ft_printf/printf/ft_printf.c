/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:15:45 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 03:15:47 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cutch(va_list args, const char **format, int *counter, int *res)
{
	int tmp;

	tmp = makeformatstr(&*format, *counter, args);
	if (tmp == -2)
		return (-1);
	*counter = 0;
	*res += tmp;
	return (tmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;
	int		counter;
	int		tmp;

	tmp = 0;
	res = 0;
	counter = 0;
	va_start(args, format);
	while (format[counter])
	{
		if (!ft_strchr(format, '%'))
		{
			res += pf_putstr(format);
			break ;
		}
		if (format[counter] == '%')
			tmp = ft_cutch(args, &format, &counter, &res);
		else
			counter++;
	}
	va_end(args);
	if (tmp == -1)
		res = -1;
	return (res);
}
