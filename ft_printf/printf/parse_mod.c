/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:40:50 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:40:51 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_findnumber(char *format_str, int *start)
{
	int		counter;
	char	*accept;
	int		number;

	counter = *start;
	while (ft_isdigit(format_str[counter]))
		counter++;
	accept = (char*)malloc(sizeof(char) * (counter - *start + 1));
	counter = 0;
	while (ft_isdigit(format_str[*start]))
	{
		accept[counter] = format_str[*start];
		*start += 1;
		counter++;
	}
	accept[counter] = '\0';
	number = ft_atoi(accept);
	free(accept);
	return (number);
}

void	ft_ifdigit(char *format_str, int *counter, int *tmp, int *modificators)
{
	if (format_str[*counter - 1] == '.')
	{
		if (!ft_isdigit(format_str[*counter]))
		{
			modificators[1] = -1;
			*counter += 1;
		}
		else
		{
			modificators[1] = ft_findnumber(format_str, counter);
			if (!modificators[1])
				modificators[1] = -1;
		}
	}
	else
	{
		*tmp = ft_findnumber(format_str, counter);
		if (*tmp)
			modificators[0] = *tmp;
	}
}

int		*ft_modificators(int *modificators, char *format_str, va_list args)
{
	int counter;
	int tmp;

	counter = 0;
	modificators[0] = 0;
	modificators[1] = 0;
	while (format_str[counter])
	{
		if (format_str[counter] == '*')
		{
			if (format_str[counter - 1] == '.')
				modificators[1] = va_arg(args, int);
			else
				modificators[0] = va_arg(args, int);
			counter++;
		}
		else if (ft_isdigit(format_str[counter])
			|| format_str[counter - 1] == '.')
			ft_ifdigit(format_str, &counter, &tmp, modificators);
		else
			counter++;
	}
	return (modificators);
}
