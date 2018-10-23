/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:53:04 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:53:05 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

void (*g_funx[4])(t_info *info, t_ssl *) =
{
	NULL, ft_md5, ft_sha256, ft_sha512
};

void	ft_manage(t_ssl *ssl, t_info *c_info)
{
	g_funx[ssl->is_md5](c_info, ssl);
	if (ssl->is_md5 == 1)
	{
		ft_make_print(ssl, c_info, "MD5");
		free(ssl->msg);
	}
	else if (ssl->is_md5 == 2)
		ft_make_print(ssl, c_info, "SHA256");
	else if (ssl->is_md5 == 3)
		ft_make_print(ssl, c_info, "SHA512");
}

void	ft_make_hash(t_ssl *ssl, t_info *info)
{
	t_info	*c_info;

	c_info = info->next;
	while (c_info)
	{
		if (!c_info->data)
			ft_print_error(ssl, c_info);
		else
			ft_manage(ssl, c_info);
		c_info = c_info->next;
		if (c_info)
			ft_printf("\n");
	}
}
