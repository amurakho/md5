/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:45 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:46 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

char	*my_itoa_basemax(uintmax_t num, size_t base, int is_bigger)
{
	char		*base_str;
	char		*str;
	uintmax_t	c_num;
	int			size;

	if (is_bigger)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	c_num = num;
	size = 1;
	while (c_num > base - 1)
	{
		c_num /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size--)
	{
		str[size] = base_str[num % base];
		num /= base;
	}
	return (str);
}

void	ft_print_md5(t_ssl *ssl)
{
	uint8_t	*p;
	char	*hash;
	int		counter;
	int		s_counter;
	size_t	len;

	s_counter = 0;
	counter = 0;
	while (counter != 4)
	{
		p = (uint8_t *)&ssl->hash[counter];
		while (s_counter != 4)
		{
			hash = my_itoa_basemax(p[s_counter], 16, 0);
			len = ft_strlen(hash);
			while (len++ < 2)
				ft_putchar('0');
			ft_putstr(hash);
			free(hash);
			s_counter++;
		}
		s_counter = 0;
		counter++;
	}
}

void	ft_print_sha(t_ssl *ssl)
{
	uint8_t	*p;
	char	*hash;
	int		counter;
	int		s_counter;
	size_t	len;

	s_counter = 3;
	counter = 0;
	while (counter != 8)
	{
		p = (uint8_t *)&ssl->hash[counter];
		while (s_counter >= 0)
		{
			hash = my_itoa_basemax(p[s_counter], 16, 0);
			len = ft_strlen(hash);
			while (len++ < 2)
				ft_putchar('0');
			ft_putstr(hash);
			free(hash);
			s_counter--;
		}
		s_counter = 3;
		counter++;
	}
}

void	ft_print_sha512(t_ssl *ssl)
{
	uint16_t	*p;
	char		*hash;
	int			counter;
	int			s_counter;
	size_t		len;

	s_counter = 3;
	counter = 0;
	while (counter != 8)
	{
		p = (uint16_t *)&ssl->hash512[counter];
		while (s_counter >= 0)
		{
			hash = my_itoa_basemax(p[s_counter], 16, 0);
			len = ft_strlen(hash);
			while (len++ < 4)
				ft_putchar('0');
			ft_putstr(hash);
			free(hash);
			s_counter--;
		}
		s_counter = 3;
		counter++;
	}
}

void	ft_print_hash(t_ssl *ssl)
{
	if (ssl->is_md5 == 1)
		ft_print_md5(ssl);
	else if (ssl->is_md5 == 2)
		ft_print_sha(ssl);
	else if (ssl->is_md5 == 3)
		ft_print_sha512(ssl);
}
