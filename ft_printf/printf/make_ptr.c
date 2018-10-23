/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:58:46 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 02:58:48 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printptr(char *str, int **full, char type)
{
	int len;
	int space;
	int tmp;

	len = ft_strlen(str);
	space = full[1][0] - len;
	tmp = space;
	if (len > space && full[0][4] && space > 0)
	{
		write(1, "0x", 2);
		str += 2;
		while (space--)
			write(1, "0", 1);
		ft_putstr(str);
	}
	else
		return (ft_makestrwidth(str, full[1], full[0], type));
	return (len + tmp);
}

int		ft_ifaccept(int **full, char *str, char type)
{
	char	*new_str;
	size_t	counter;
	char	*tmp;
	size_t	len;
	int		res;

	new_str = ft_memalloc(full[1][1] + 2);
	counter = 1;
	new_str = ft_strcpy(new_str, "0x");
	str += 2;
	len = ft_strlen(str);
	while (counter++ != full[1][1] - len + 1)
		new_str[counter] = '0';
	tmp = ft_strjoin(new_str, str);
	res = ft_printptr(tmp, full, type);
	free(new_str);
	free(tmp);
	return (res);
}

int		ft_makeptr(char *str, int **full, char type)
{
	int		size;
	char	*tmp;

	if (full[1][1] == -1 && !str[3])
		tmp = ft_strdup("0x");
	else
		tmp = ft_strdup(str);
	if ((full[1][1] > (int)ft_strlen(str) - 2) && full[1][1] != -1)
		size = ft_ifaccept(full, tmp, type);
	else
		size = ft_printptr(tmp, full, type);
	free(str);
	free(tmp);
	return (size);
}
