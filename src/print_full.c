/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:40 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:41 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

void	ft_make_print1(t_ssl *ssl, t_info *info, char *algo)
{
	if (info->type == 2 && !ssl->reverse && !ssl->quiet)
	{
		ft_printf("%s (\"%s\") = ", algo, info->data);
		ft_print_hash(ssl);
	}
	else if (ssl->reverse && info->type == 2 && !ssl->quiet)
	{
		ft_print_hash(ssl);
		ft_printf(" \"%s\"", info->data);
	}
	else
		ft_print_hash(ssl);
}

void	ft_make_print(t_ssl *ssl, t_info *info, char *algo)
{
	if (ssl->is_print && info->type == 1)
	{
		ft_printf("%s", info->data);
		ft_print_hash(ssl);
	}
	else if (info->type == 3 && !ssl->reverse && !ssl->quiet)
	{
		ft_printf("%s (%s) = ", algo, info->file);
		ft_print_hash(ssl);
	}
	else if (ssl->reverse && info->type == 3 && !ssl->quiet)
	{
		ft_print_hash(ssl);
		ft_printf(" %s", info->file);
	}
	else
		ft_make_print1(ssl, info, algo);
}

void	ft_print_error(t_ssl *ssl, t_info *info)
{
	if (ssl->is_md5 == 1)
		ft_printf("ft_ssl: md5: %s: No such file or directory", info->file);
	else if (ssl->is_md5 == 2)
		ft_printf("ft_ssl: sha: %s: No such file or directory", info->file);
	else if (ssl->is_md5 == 3)
		ft_printf("ft_ssl: sha512: %s: No such file or directory", info->file);
}
