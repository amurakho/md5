/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:13 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:15 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

uint64_t	ft_rightrotate512(uint64_t value, unsigned int count)
{
	return (value >> count | value << (64 - count));
}

uint64_t	revers_uint64(uint64_t w)
{
	uint64_t	tmp;

	tmp = (w >> 32) | (w << 32);
	tmp = ((tmp & 0xff00ff00ff00ff00ULL) >> 8) |
	((tmp & 0x00ff00ff00ff00ffULL) << 8);
	return (((tmp & 0xffff0000ffff0000ULL) >> 16) |
		((tmp & 0x0000ffff0000ffffULL) << 16));
}

void		ft_make_sha512(t_sha512 *sha512)
{
	sha512->hash[0] = 0x6a09e667f3bcc908;
	sha512->hash[1] = 0xbb67ae8584caa73b;
	sha512->hash[2] = 0x3c6ef372fe94f82b;
	sha512->hash[3] = 0xa54ff53a5f1d36f1;
	sha512->hash[4] = 0x510e527fade682d1;
	sha512->hash[5] = 0x9b05688c2b3e6c1f;
	sha512->hash[6] = 0x1f83d9abfb41bd6b;
	sha512->hash[7] = 0x5be0cd19137e2179;
}

void		ft_add_to_ssl(t_ssl *ssl, t_sha512 *sha512)
{
	ssl->hash512[0] = sha512->hash[0];
	ssl->hash512[1] = sha512->hash[1];
	ssl->hash512[2] = sha512->hash[2];
	ssl->hash512[3] = sha512->hash[3];
	ssl->hash512[4] = sha512->hash[4];
	ssl->hash512[5] = sha512->hash[5];
	ssl->hash512[6] = sha512->hash[6];
	ssl->hash512[7] = sha512->hash[7];
}

void		ft_re_hash(t_sha512 *sha512)
{
	sha512->hash[0] += sha512->a;
	sha512->hash[1] += sha512->b;
	sha512->hash[2] += sha512->c;
	sha512->hash[3] += sha512->d;
	sha512->hash[4] += sha512->e;
	sha512->hash[5] += sha512->f;
	sha512->hash[6] += sha512->g;
	sha512->hash[7] += sha512->h;
}
