/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_number_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:20:44 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 05:20:46 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ifhash(char type, char *str, int **full)
{
	int		counter;
	char	*tmp;

	tmp = NULL;
	if (type == 'x' && fz(str))
		tmp = ft_strjoin("0x", str);
	if (type == 'X' && fz(str))
		tmp = ft_strjoin("0X", str);
	if ((type == 'O' || type == 'o') && fz(str))
		tmp = ft_strjoin("0", str);
	if (tmp)
	{
		counter = ft_parsetype(tmp, full, type);
		ft_strdel(&tmp);
	}
	else
		counter = ft_parsetype(str, full, type);
	if (ft_strlen(str))
		ft_strdel(&str);
	return (counter);
}

int		ft_crutch(int **full, char type, char *new_str)
{
	int counter;

	if (full[0][3])
		counter = ft_ifhash(type, new_str, full);
	else
	{
		counter = ft_parsetype(new_str, full, type);
		free(new_str);
	}
	return (counter);
}

int		ft_makeaccept(char *old, int **full, char type)
{
	char	*new_str;
	size_t	len;
	int		counter;
	char	*tmp;

	len = ft_strlen(old);
	if (old[0] == '-')
	{
		len--;
		full[1][1]++;
	}
	new_str = ft_memalloc(full[1][1]);
	ft_memset(new_str, '0', full[1][1] - len);
	if (old[0] == '-')
	{
		new_str[0] = '-';
		old++;
	}
	tmp = ft_strcat(new_str, old);
	counter = ft_crutch(full, type, tmp);
	return (counter);
}

char	*ft_editline(int *len, char *str, int **full, char type)
{
	if (*len == 1 && str[0] == '0' &&
		full[1][1] == -1 && (type == 'x' || type == 'X'))
	{
		free(str);
		return ("");
	}
	if (*len == 1 && str[0] == '0' && full[1][1] == -1 && !full[0][3])
	{
		free(str);
		return ("");
	}
	if (str[0] == '-')
		*len -= 1;
	return (str);
}

int		ft_makeprintbl(char *str, int **full, char t)
{
	int len;
	int counter;

	counter = 0;
	len = ft_strlen(str);
	if (str)
	{
		str = ft_editline(&len, str, full, t);
		if (full[0][3] && full[1][1] > 0 && (t == 'o' || t == 'O') && fz(str))
			full[1][1]--;
		if (len < full[1][1])
		{
			counter = ft_makeaccept(str, full, t);
			free(str);
		}
		else if (full[0][3])
			counter = ft_ifhash(t, str, full);
	}
	if (!counter)
	{
		counter = ft_parsetype(str, full, t);
		if (ft_strlen(str))
			ft_strdel(&str);
	}
	return (counter);
}
