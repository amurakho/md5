/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:56:07 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:56:13 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*makebase(char type, intmax_t number)
{
	char	*str;

	str = NULL;
	if (type == 'd' || type == 'i' || type == 'D')
		str = ft_itoamax(number);
	if (type == 'o' || type == 'O')
		str = my_itoa_basemax(number, 8, 0);
	if (type == 'u' || type == 'U')
		str = my_itoa_basemax(number, 10, 0);
	if (type == 'x')
		str = my_itoa_basemax(number, 16, 0);
	if (type == 'X')
		str = my_itoa_basemax(number, 16, 1);
	return (str);
}

char	*upreparetosize(int flag, va_list args, char type)
{
	uintmax_t	number;

	if (flag == 1)
		number = va_arg(args, uintmax_t);
	else if (flag == 2)
		number = va_arg(args, size_t);
	else if (flag == 3)
		number = va_arg(args, unsigned long long int);
	else if (flag == 4 || type == 'U' || type == 'O')
		number = va_arg(args, unsigned long int);
	else if (flag == 5)
		number = (unsigned char)va_arg(args, unsigned int);
	else if (flag == 6)
		number = (unsigned short int)va_arg(args, unsigned int);
	else
		number = va_arg(args, unsigned int);
	return (makebase(type, number));
}

char	*preparetosize(int flag, va_list args, char type)
{
	intmax_t	number;

	if (flag == 1)
		number = va_arg(args, intmax_t);
	else if (flag == 2)
		number = va_arg(args, size_t);
	else if (flag == 3)
		number = va_arg(args, long long int);
	else if (flag == 4 || type == 'D')
		number = va_arg(args, long int);
	else if (flag == 5)
		number = (char)va_arg(args, int);
	else if (flag == 6)
		number = (short int)va_arg(args, int);
	else
		number = va_arg(args, int);
	return (makebase(type, number));
}
