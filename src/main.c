/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:51:58 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:02 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

char	*ft_mystrjoin(char *s1, char const *s2, size_t f_len, size_t s_len)
{
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * (f_len + s_len));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, f_len);
	ft_memcpy(new_str + f_len, (char*)s2, s_len);
	free(s1);
	return (new_str);
}

t_ssl	*ft_make_ssl(t_ssl *ssl, char *str)
{
	ssl->reverse = 0;
	ssl->is_print = 0;
	ssl->quiet = 0;
	ssl->is_string = 0;
	ssl->is_file = 0;
	ssl->in_flag = 0;
	ssl->str_count = 0;
	if (ft_strequ(str, "md5"))
		ssl->is_md5 = 1;
	else if (ft_strequ(str, "sha256"))
		ssl->is_md5 = 2;
	else if (ft_strequ(str, "sha512"))
		ssl->is_md5 = 3;
	else
	{
		printf("Error: need params: md5/sha256/sha512");
		exit(1);
	}
	return (ssl);
}

int		main(int argc, char **argv)
{
	t_ssl	*ssl;
	t_info	*info;
	int		counter;

	info = (t_info*)malloc(sizeof(t_info));
	info->next = NULL;
	ssl = (t_ssl*)malloc(sizeof(t_ssl));
	ft_make_ssl(ssl, argv[1]);
	counter = ft_parse_flags(ssl, argv, argc);
	if ((!ssl->is_file && !ssl->is_string) || ssl->is_print)
		ft_try_echo(info);
	if (counter + 1 != argc && counter != argc && !ssl->is_file)
		counter++;
	if (ssl->in_flag)
		argv[counter] += 2;
	while (argv[counter])
	{
		if (ft_strequ(argv[counter], "-s") && ssl->is_string
			&& (ssl->is_string != ssl->str_count + 1))
			counter++;
		ft_parse_info(ssl, info, argv[counter]);
		counter++;
	}
	ft_make_hash(ssl, info);
	return (0);
}
