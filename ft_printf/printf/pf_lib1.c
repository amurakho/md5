/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:44:46 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:44:51 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

char	*my_itoa_base(intptr_t num, int base, int is_bigger)
{
	char		*base_str;
	char		*str;
	intptr_t	c_num;
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

char	*printmemory(va_list args)
{
	intptr_t	number;
	void		*ptr;
	char		*str;
	char		*base;

	base = "0x";
	ptr = va_arg(args, void*);
	number = (intptr_t)ptr;
	str = my_itoa_base(number, 16, 0);
	base = ft_strjoin(base, str);
	free(str);
	return (base);
}

wchar_t	*pf_strncpy(wchar_t *destptr, const wchar_t *srcptr, int num)
{
	unsigned int counter;

	counter = 0;
	while (srcptr[counter] != '\0' && num > 0)
	{
		if (srcptr[counter] > 127)
		{
			num -= 3;
			if (num < 0)
				break ;
		}
		else
			num--;
		destptr[counter] = srcptr[counter];
		counter++;
	}
	destptr[counter] = '\0';
	while (num > 0)
	{
		destptr[counter] = '\0';
		counter++;
		num--;
	}
	return (destptr);
}

size_t	pf_strlen(wchar_t *str)
{
	wint_t	res;
	int		counter;

	res = 0;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] > 127)
			res += 3;
		else
			res++;
		counter++;
	}
	return (res);
}

int		pf_putstr(const char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
	{
		write(1, &str[counter], 1);
		counter++;
	}
	return (counter);
}
