/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:43:32 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/03 10:43:33 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_FT_SSL_MD5_H
# define FT_SSL_MD5_FT_SSL_MD5_H
# include "../libft/libft.h"
# include "../ft_printf/printf/ft_printf.h"
# include <wchar.h>
# include <stdint.h>
# include <fcntl.h>
# define BUFF 4098

typedef struct		s_md5
{
	size_t			offset;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		f;
	uint32_t		*w;
}					t_md5;

typedef struct		s_sha
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		*w;
	size_t			offset;
	uint32_t		*msg;
}					t_sha;

typedef struct		s_sha512
{
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
	uint64_t		*w;
	uint64_t		hash[8];
	size_t			offset;
	uint64_t		*msg;
}					t_sha512;

typedef struct		s_info
{
	char			*data;
	struct s_info	*next;
	int				type;
	char			*file;
	int				info_len;
}					t_info;

typedef struct		s_ssl
{
	int				reverse;
	int				quiet;
	unsigned char	*msg;
	int				in_flag;
	int				is_string;
	int				is_print;
	int				is_file;
	int				is_md5;
	uint32_t		hash[8];
	uint64_t		hash512[8];
	int				str_count;
}					t_ssl;

char				*ft_mystrjoin(char *s1, char const *s2,
	size_t f_len, size_t s_len);
size_t				ft_to_bytes(char *str, size_t len, t_ssl *ssl);
void				ft_md5(t_info *info, t_ssl *ssl);
char				*ft_parse_file(char *file_name, t_ssl *ssl, t_info *info);
char				*ft_parse_echo();
int					ft_parse_flags(t_ssl *ssl, char **argv, int argc);
void				ft_parse_info(t_ssl *ssl, t_info *info, char *str);
void				ft_try_echo(t_info *info);
void				ft_make_hash(t_ssl *ssl, t_info *info);
void				ft_make_print(t_ssl *ssl, t_info *info, char *algo);
void				ft_print_error(t_ssl *ssl, t_info *info);
void				ft_sha256(t_info *info, t_ssl *ssl);
void				ft_sha512(t_info *info, t_ssl *ssl);
uint64_t			ft_rightrotate512(uint64_t value, unsigned int count);
uint32_t			ft_rightrotate(uint32_t value, unsigned int count);
void				ft_make_sha(t_sha *sha, size_t len, t_ssl *ssl);
uint32_t			revers_uint32(uint32_t n);
uint64_t			revers_uint64(uint64_t n);
void				ft_make_sha512(t_sha512 *sha512);
void				ft_add_to_ssl(t_ssl *ssl, t_sha512	*sha512);
void				ft_print_hash(t_ssl *ssl);
void				ft_re_hash(t_sha512	*sha512);
int					ft_parse_flags(t_ssl *ssl, char **argv, int argc);
#endif
