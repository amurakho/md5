/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:27 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:29 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

size_t	ft_to_bytes(char *str, size_t len, t_ssl *ssl)
{
	size_t			size_bytes;
	uint32_t		bits_len;

	size_bytes = (len * 8) + 1;
	while (size_bytes % 512 != 448)
		size_bytes++;
	size_bytes /= 8;
	ssl->msg = ft_memalloc(size_bytes + 64);
	ssl->msg = ft_memcpy(ssl->msg, str, len);
	ssl->msg[len] = 0x80;
	bits_len = (u_int32_t)(8 * len);
	ft_memcpy(ssl->msg + size_bytes, &bits_len, 4);
	return (size_bytes);
}
