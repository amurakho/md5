/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myitoabasemax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:09:08 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 03:09:10 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_itoa_basemax(uintmax_t num, size_t base, int is_bigger)
{
	char		*base_str;
	char		*str;
	uintmax_t	c_num;
	int			size;

	if (is_bigger)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	c_num = num;
	size = 1;
	while (c_num > base - 1)
	{
		c_num /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size--)
	{
		str[size] = base_str[num % base];
		num /= base;
	}
	return (str);
}
