/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecharl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:02:51 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 03:02:54 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(int *format, char *str, char type, int spaces)
{
	char	symbol;

	symbol = ' ';
	if (format[4] && !format[1])
		symbol = '0';
	if (format[1])
	{
		if (!str[0] && type == 'C')
			write(1, &str[0], 1);
		else
			ft_putstr(str);
		while (spaces-- > 0)
			ft_putchar(symbol);
	}
	else
	{
		while (spaces-- > 0)
			ft_putchar(symbol);
		if (!str[0] && type == 'C')
			write(1, &str[0], 1);
		else
			ft_putstr(str);
	}
}

int		ft_makestrwwidth(char *str, int spaces, int *format, char type)
{
	int		tmp;

	tmp = 0;
	if (spaces > 0)
		tmp = spaces;
	ft_printstr(format, str, type, spaces);
	if (type == 'C' && ft_strlen(str) == 0)
		return (tmp + 1);
	else
		return (tmp + (ft_strlen(str)));
}

int		ft_makewprintbl(char *str, int **full, char type)
{
	size_t	len;
	int		counter;

	len = ft_strlen(str);
	if (!str)
		str = "null";
	if (!str[0])
		full[1][0]--;
	counter = ft_makestrwwidth(str, full[1][0] - len, full[0], type);
	free(str);
	return (counter);
}

char	*ft_makeuni(wint_t code, char *new_str)
{
	if (code <= 0x7F)
		new_str[0] = (char)code;
	else if (code <= 0x7FF)
	{
		new_str[0] = (((code & 0x07c0) >> 6) + 0xc0);
		new_str[1] = ((code & 0x003F) + 0x80);
	}
	else if (code <= 0xFFFF)
	{
		new_str[0] = (((code & 0xF000) >> 12) + 0xE0);
		new_str[1] = (((code & 0x0Fc0) >> 6) + 0x80);
		new_str[2] = ((code & 0x003F) + 0x80);
	}
	else if (code <= 0x10FFFF)
	{
		new_str[0] = (((code & 0x1c0000) >> 18) + 0xF0);
		new_str[1] = (((code & 0x03F000) >> 12) + 0x80);
		new_str[2] = (((code & 0x0Fc0) >> 6) + 0x80);
		new_str[3] = ((code & 0x003F) + 0x80);
	}
	return (new_str);
}

char	*ft_makewchar(wchar_t symbol)
{
	wint_t	code;
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * 5);
	new_str = ft_memset(new_str, '\0', 5);
	code = symbol;
	new_str = ft_makeuni(code, new_str);
	return (new_str);
}
