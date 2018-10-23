/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:07 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:08 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

uint32_t	ft_rightrotate(uint32_t value, unsigned int count)
{
	return (value >> count | value << (32 - count));
}

uint32_t	revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
			((n & 0xff00) << 8) | (n << 24));
}

void		ft_make_sha(t_sha *sha, size_t len, t_ssl *ssl)
{
	ssl->hash[0] = 0x6A09E667;
	ssl->hash[1] = 0xBB67AE85;
	ssl->hash[2] = 0x3C6EF372;
	ssl->hash[3] = 0xA54FF53A;
	ssl->hash[4] = 0x510E527F;
	ssl->hash[5] = 0x9B05688C;
	ssl->hash[6] = 0x1F83D9AB;
	ssl->hash[7] = 0x5BE0CD19;
	sha->offset = (1 + ((len + 16 + 64) / 512));
}
