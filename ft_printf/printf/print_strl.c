/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:26:41 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:26:42 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fullascii(wchar_t *str)
{
	wint_t counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] > 127)
			return (0);
		counter++;
	}
	return (1);
}

int	ft_printwstr(wchar_t *new_str, char *old, int **full)
{
	int res;

	if (ft_fullascii(new_str))
	{
		res = pf_putstr(old);
		res += ft_makewwidht(new_str, full);
		if (MB_CUR_MAX == 1)
			return (-1);
		else
			return (res);
	}
	else
	{
		if (MB_CUR_MAX != 1)
		{
			res = pf_putstr(old);
			res += ft_makewwidht(new_str, full);
			return (res);
		}
		return (-2);
	}
}
