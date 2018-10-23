/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:56:56 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:56:58 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_makeprintstr(char *str, int **full, char type)
{
	char	*new_str;
	int		res;

	if (!str)
		str = "(null)";
	if (!str[0])
		full[1][0]--;
	if ((int)ft_strlen(str) > full[1][1] && full[1][1] != 0)
	{
		if (full[1][1] < 0)
			return (ft_makestrwidth("", full[1], full[0], type));
		else
		{
			if (!str[0])
				full[1][1]--;
			new_str = ft_memalloc(full[1][1]);
			new_str = ft_strncpy(new_str, str, full[1][1]);
			new_str[full[1][1]] = '\0';
			res = ft_makestrwidth(new_str, full[1], full[0], type);
			free(new_str);
			return (res);
		}
	}
	else
		return (ft_makestrwidth(str, full[1], full[0], type));
}
