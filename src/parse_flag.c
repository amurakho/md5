/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:13:47 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/06 15:13:49 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

int		ft_ifflag(t_ssl *ssl, char **argv, int *counter)
{
	if (argv[*counter][1] == 's')
	{
		if (ft_strlen(argv[*counter]) > 2 && !ssl->in_flag)
		{
			ssl->in_flag = 1;
			*counter -= 1;
		}
		else
			ssl->str_count++;
		ssl->is_string = 1;
	}
	else if (argv[*counter][1] == 'p')
		ssl->is_print = 1;
	else if (argv[*counter][1] == 'q')
		ssl->quiet = 1;
	else if (argv[*counter][1] == 'r')
		ssl->reverse = 1;
	else
	{
		printf("ft_ssl: illegal option -- %c\n", argv[*counter][1]);
		printf("usage: ft_ssl [alogo] [-s/-p/-q/-r] [files ...]\n");
		exit(1);
	}
	return (1);
}

int		ft_parse_flags(t_ssl *ssl, char **argv, int argc)
{
	int counter;

	counter = 2;
	if (argc == counter)
		return (argc);
	while (counter != argc)
	{
		if (argv[counter][0] == '-')
			ft_ifflag(ssl, argv, &counter);
		else if (!ft_strequ(argv[counter - 1], "-s"))
		{
			ssl->is_file = 1;
			break ;
		}
		counter++;
	}
	if (ssl->in_flag)
		return (counter - 1);
	else
		return (counter - ssl->str_count * 2);
}
