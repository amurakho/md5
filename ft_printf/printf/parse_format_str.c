/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:38:26 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:38:28 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	workingformat(char *format_str, size_t len, va_list args, char *str)
{
	int	*format;
	int	*modificators;
	int	*flag;
	int	*full[3];
	int	counter;

	format = (int*)malloc(sizeof(int) * 5);
	full[0] = ft_findformat(format_str, format);
	modificators = (int*)malloc(sizeof(int) * 3);
	full[1] = ft_modificators(modificators, format_str, args);
	if (full[1][0] < 0)
	{
		full[1][0] = full[1][0] * -1;
		full[0][1] = 1;
	}
	if (full[1][1] < 0)
		full[1][2] = 0;
	flag = (int*)malloc(sizeof(int));
	flag[0] = ft_findflag(format_str, "jzlh");
	full[2] = flag;
	counter = ft_parse(format_str[len], full, args, str);
	free(format);
	free(flag);
	free(modificators);
	return (counter);
}
