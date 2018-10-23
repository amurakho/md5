/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makenumberw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:51:57 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:52:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsetype(char *str, int **full, char type)
{
	char	symbol;
	int		spaces;
	int		counter;

	spaces = full[1][0] - ft_strlen(str);
	symbol = ' ';
	counter = 0;
	if (full[0][4] && !full[0][1] && !full[1][1] && full[1][1] != -1)
		symbol = '0';
	if (full[1][1])
	{
		full[0][3] = 0;
		full[0][4] = 0;
	}
	if (type == 'd' || type == 'D' || type == 'i')
		if (full[0][1])
			counter = ft_ifformat(str, full[0], spaces, symbol);
		else
			counter = ft_ifnformat(str, full[0], spaces, symbol);
	else if (type == 'x' || type == 'X' || type == 'u'
		|| type == 'U' || type == 'o' || type == 'O')
		counter = ft_ifnotint(str, full[0], symbol, spaces);
	return (counter);
}
