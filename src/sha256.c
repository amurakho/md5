/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:51 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:55 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

u_int32_t	g_sq[] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

void		sha256_msg(char *init_mg, size_t len, t_sha *sha)
{
	size_t	i;
	size_t	size_bytes;

	size_bytes = len * 8;
	sha->offset = 1 + ((size_bytes + 16 + 64) / 512);
	sha->msg = ft_memalloc(16 * sha->offset * 4);
	ft_memcpy((char *)sha->msg, init_mg, len);
	((char*)sha->msg)[len] = 0x80;
	i = 0;
	while (i < (sha->offset * 16) - 1)
	{
		sha->msg[i] = revers_uint32(sha->msg[i]);
		i++;
	}
	sha->msg[((sha->offset * 512 - 64) / 32) + 1] = size_bytes;
}

void		ft_magic_sha(t_sha *sha, int j)
{
	uint32_t tmp;
	uint32_t tmp2;
	uint32_t tmp4;
	uint32_t tmp5;
	uint32_t tmp6;

	tmp = ft_rightrotate(sha->e, 6) ^
		ft_rightrotate(sha->e, 11) ^ ft_rightrotate(sha->e, 25);
	tmp2 = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	tmp2 = sha->h + tmp + tmp2 + g_sq[j] + sha->w[j];
	tmp4 = ft_rightrotate(sha->a, 2) ^
		ft_rightrotate(sha->a, 13) ^ ft_rightrotate(sha->a, 22);
	tmp5 = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
	tmp6 = tmp4 + tmp5;
	sha->h = sha->g;
	sha->g = sha->f;
	sha->f = sha->e;
	sha->e = sha->d + tmp2;
	sha->d = sha->c;
	sha->c = sha->b;
	sha->b = sha->a;
	sha->a = tmp2 + tmp6;
}

void		make_hash(t_sha *sha, size_t i, t_ssl *ssl)
{
	int			j;
	uint32_t	s0;
	uint32_t	s1;

	sha->w = malloc(512);
	ft_bzero(sha->w, 512);
	ft_memcpy(sha->w, &sha->msg[i * 16], 512);
	j = 16;
	while (j < 64)
	{
		s0 = ft_rightrotate(sha->w[j - 15], 7) ^
			ft_rightrotate(sha->w[j - 15], 18) ^ (sha->w[j - 15] >> 3);
		s1 = ft_rightrotate(sha->w[j - 2], 17) ^
			ft_rightrotate(sha->w[j - 2], 19) ^ (sha->w[j - 2] >> 10);
		sha->w[j] = sha->w[j - 16] + s0 + sha->w[j - 7] + s1;
		j++;
	}
	sha->a = ssl->hash[0];
	sha->b = ssl->hash[1];
	sha->c = ssl->hash[2];
	sha->d = ssl->hash[3];
	sha->e = ssl->hash[4];
	sha->f = ssl->hash[5];
	sha->g = ssl->hash[6];
	sha->h = ssl->hash[7];
}

void		ft_add_to_hash(t_ssl *ssl, t_sha *sha)
{
	ssl->hash[0] += sha->a;
	ssl->hash[1] += sha->b;
	ssl->hash[2] += sha->c;
	ssl->hash[3] += sha->d;
	ssl->hash[4] += sha->e;
	ssl->hash[5] += sha->f;
	ssl->hash[6] += sha->g;
	ssl->hash[7] += sha->h;
}

void		ft_sha256(t_info *info, t_ssl *ssl)
{
	size_t	i;
	int		j;
	t_sha	*sha;

	sha = (t_sha*)malloc(sizeof(t_sha));
	ft_make_sha(sha, info->info_len * 8, ssl);
	sha256_msg(info->data, info->info_len, sha);
	i = 0;
	while (i < sha->offset)
	{
		make_hash(sha, i, ssl);
		j = -1;
		while (++j < 64)
			ft_magic_sha(sha, j);
		ft_add_to_hash(ssl, sha);
		free(sha->w);
		i++;
	}
	free(sha->msg);
	free(sha);
}
