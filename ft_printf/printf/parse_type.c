/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:37:36 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:37:38 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(char t, int **full, va_list ar, char *str)
{
	int res;

	res = 0;
	if (t == 'S' || (t == 's' && full[2][0] == 4))
		res = ft_makewstr(va_arg(ar, wchar_t*), full, str);
	else
	{
		res += pf_putstr(str);
		if (t == 'd' || t == 'i' || t == 'D')
			res += ft_makeprintbl(preparetosize(full[2][0], ar, t), full, t);
		else if (t == 'o' || t == 'u' || t == 'x'
			|| t == 'X' || t == 'U' || t == 'O')
			res += ft_makeprintbl(upreparetosize(full[2][0], ar, t), full, t);
		else if (t == 'C' || (t == 'c' && full[2][0] == 4))
			res += ft_makewprintbl(ft_makewchar(va_arg(ar, wchar_t)), full, t);
		else if (t == 'p')
			res += ft_makeptr(printmemory(ar), full, t);
		else if (t == 's')
			res += ft_makeprintstr(va_arg(ar, char*), full, t);
		else
			res += ft_makediff(t, full, ar);
	}
	return (res);
}
