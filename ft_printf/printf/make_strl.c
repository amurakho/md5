/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:48:34 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:48:37 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printw(wchar_t *str, int accept)
{
	int		counter;
	char	*new_str;
	int		size;

	size = 0;
	counter = 0;
	while (str[counter])
	{
		if (counter > accept && accept)
			break ;
		new_str = ft_makewchar(str[counter]);
		size += ft_strlen(new_str);
		ft_putstr(new_str);
		free(new_str);
		counter++;
	}
	return (size);
}

int	ft_findsymbol(wchar_t *str, int **full, char *symbol)
{
	int spaces;

	spaces = full[1][0] - (pf_strlen(str));
	*symbol = ' ';
	if (full[0][4] && !full[0][1])
		*symbol = '0';
	return (spaces);
}

int	ft_makewstr(wchar_t *str, int **full, char *old)
{
	wchar_t		*new_str;
	int			len;
	int			res;

	if (!str)
	{
		res = pf_putstr(old);
		res += ft_makeprintstr("(null)", full, 's');
		return (res);
	}
	len = pf_strlen(str);
	if (len > full[1][1] && full[1][1] != 0)
	{
		if (!str[0])
			full[1][1]--;
		if (full[1][1] == -1)
			full[1][1] = 0;
		new_str = (wchar_t*)malloc(sizeof(wchar_t) * full[1][1]);
		new_str = pf_strncpy(new_str, str, full[1][1]);
		res = ft_printwstr(new_str, old, full);
		free(new_str);
	}
	else
		res = ft_printwstr(str, old, full);
	return (res);
}
