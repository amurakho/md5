/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:00:26 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/14 11:00:27 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fz(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] != '0')
			return (1);
		counter++;
	}
	return (0);
}
