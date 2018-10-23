/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:19 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:20 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

uint32_t	g_sin[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

uint32_t	g_pos[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

uint32_t	ft_leftrotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x) >> (32 - c));
}

uint32_t	ft_funx(uint32_t counter, t_md5 *md5)
{
	uint32_t	c_counter;

	if (counter < 16)
	{
		md5->f = (md5->b & md5->c) | ((~md5->b) & md5->d);
		c_counter = counter;
	}
	else if (counter < 32)
	{
		md5->f = (md5->d & md5->b) | ((~md5->d) & md5->c);
		c_counter = (5 * counter + 1) % 16;
	}
	else if (counter < 48)
	{
		md5->f = md5->b ^ md5->c ^ md5->d;
		c_counter = (3 * counter + 5) % 16;
	}
	else
	{
		md5->f = md5->c ^ (md5->b | (~md5->d));
		c_counter = (7 * counter) % 16;
	}
	return (c_counter);
}

void		ft_magic(t_md5 *md5)
{
	uint32_t	counter;
	uint32_t	tmp;
	uint32_t	c_counter;

	counter = 0;
	while (counter < 64)
	{
		c_counter = ft_funx(counter, md5);
		tmp = md5->b + ft_leftrotate((md5->a + md5->f +
				g_sin[counter] + md5->w[c_counter]), g_pos[counter]);
		md5->a = md5->d;
		md5->d = md5->c;
		md5->c = md5->b;
		md5->b = tmp;
		counter++;
	}
}

void		ft_make_md(t_md5 *md5, t_ssl *ssl)
{
	md5->offset = 0;
	ssl->hash[0] = 0x67452301;
	ssl->hash[1] = 0xefcdab89;
	ssl->hash[2] = 0x98badcfe;
	ssl->hash[3] = 0x10325476;
}

void		ft_md5(t_info *info, t_ssl *ssl)
{
	size_t	size_bytes;
	t_md5	*md5;
	char	*str;

	str = info->data;
	md5 = (t_md5*)malloc(sizeof(t_md5));
	ft_make_md(md5, ssl);
	size_bytes = ft_to_bytes(str, info->info_len, ssl);
	while (md5->offset < size_bytes)
	{
		md5->a = ssl->hash[0];
		md5->b = ssl->hash[1];
		md5->c = ssl->hash[2];
		md5->d = ssl->hash[3];
		md5->w = (uint32_t*)(ssl->msg + md5->offset);
		ft_magic(md5);
		ssl->hash[0] += md5->a;
		ssl->hash[1] += md5->b;
		ssl->hash[2] += md5->c;
		ssl->hash[3] += md5->d;
		md5->offset += 512 / 8;
	}
	free(md5);
}
