/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:39:19 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 04:39:20 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findflag(char *format_str, char *base)
{
	size_t	counter;
	char	*pos;

	counter = 0;
	while (base[counter])
	{
		if ((pos = ft_strchr(format_str, base[counter])))
		{
			if (*pos == 'j')
				return (1);
			else if (*pos == 'z')
				return (2);
			else if (*pos == 'l' && ft_strchr(pos + 1, 'l'))
				return (3);
			else if (*pos == 'l' && !ft_strchr(pos + 1, 'l'))
				return (4);
			else if (*pos == 'h' && ft_strchr(pos + 1, 'h'))
				return (5);
			else if (*pos == 'h' && !ft_strchr(pos + 1, 'h'))
				return (6);
		}
		counter++;
	}
	return (0);
}
