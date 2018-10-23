/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_format_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:02:21 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:02:23 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_test2(const char **f)
{
	while (**f != 'd' && **f != 'i' && **f != 'o' && **f != 'u' && **f != 'x'
			&& **f != 'X' && **f != 'p' && **f != 'c' && **f != 's'
			&& **f != 'S' && **f != 'C' && **f != 'D' && **f != 'U'
			&& **f != 'O')
	{
		if (!ft_strchr("#-+ hljz*.012,3456789", **f))
			break ;
		if (!**f)
			return (1);
		*f += 1;
	}
	return (0);
}

int	makeformatstr(const char **format, int counter, va_list args)
{
	char		*format_str;
	char		*str;
	const char	*c_format;
	int			res;

	str = (char*)malloc(sizeof(char) * counter + 1);
	str = ft_strncpy(str, *format, counter);
	str[counter] = '\0';
	*format += counter + 1;
	c_format = *format;
	if (ft_test2(*&format))
	{
		free(str);
		return (pf_putstr(str));
	}
	counter = (*format - c_format);
	*format += 1;
	format_str = (char*)malloc(sizeof(char) * (counter + 1));
	format_str = ft_strncpy(format_str, c_format, counter + 1);
	res = workingformat(format_str, counter, args, str);
	free(str);
	free(format_str);
	return (res);
}
