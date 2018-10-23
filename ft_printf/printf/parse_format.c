/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:41:27 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:41:28 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ifzero(char *format_str)
{
	int counter;
	int s_count;

	counter = 0;
	while (format_str[counter])
	{
		if (format_str[counter] == '0')
		{
			s_count = counter;
			while (format_str[s_count])
			{
				if ((format_str[s_count] <= '9' &&
					format_str[s_count] > '0') || format_str[s_count] == '.')
					break ;
				if (format_str[s_count] > '9' || format_str[s_count] < '0')
					return (1);
				s_count--;
			}
			if (!format_str[s_count])
				return (1);
		}
		counter++;
	}
	return (0);
}

int	*ft_findformat(char *format_str, int *format)
{
	int counter;

	counter = -1;
	while (counter++ != 5)
		format[counter] = 0;
	if (ft_strchr(format_str, '+'))
		format[0] = 1;
	if (ft_strchr(format_str, '-'))
		format[1] = 1;
	if (ft_strchr(format_str, ' '))
		format[2] = 1;
	if (ft_strchr(format_str, '#'))
		format[3] = 1;
	format[4] = ft_ifzero(format_str);
	return (format);
}
