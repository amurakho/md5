/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_width_strl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:29:49 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:29:52 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_makewwidht(wchar_t *str, int **full)
{
	char	symbol;
	int		spaces;
	int		size;
	int		tmp;

	spaces = ft_findsymbol(str, full, &symbol);
	tmp = spaces;
	if (full[0][1])
	{
		size = ft_printw(str, full[1][1]);
		while (spaces-- > 0)
			ft_putchar(symbol);
	}
	else
	{
		while (spaces-- > 0)
			ft_putchar(symbol);
		size = ft_printw(str, full[1][1]);
	}
	if (tmp > 0)
		return (size + tmp);
	else
		return (size);
}
