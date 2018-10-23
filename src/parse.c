/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:52:33 by amurakho          #+#    #+#             */
/*   Updated: 2018/10/04 10:52:34 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl_md5.h"

char	*ft_for_file(char *full, int file, char *tmp, t_info *info)
{
	ssize_t readst;
	int		full_size;

	readst = 0;
	full_size = 0;
	while (1)
	{
		readst = read(file, tmp, BUFF);
		if (readst == 0)
			break ;
		full = ft_mystrjoin(full, tmp, full_size, readst);
		full_size += readst;
	}
	info->info_len = full_size;
	return (full);
}

char	*ft_parse_file(char *file_name, t_ssl *ssl, t_info *info)
{
	int		file;
	char	tmp[BUFF];
	char	*full;

	full = NULL;
	if (open(file_name, O_DIRECTORY) != -1)
	{
		printf("ft_ssl: %s: Is a directory\n", file_name);
		exit(1);
	}
	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (NULL);
	full = ft_memalloc(0);
	full = ft_for_file(full, file, tmp, info);
	ssl->is_file = 1;
	return (full);
}

char	*ft_parse_echo(void)
{
	char	*tmp;
	char	*full;
	int		counter;
	char	*str;

	full = NULL;
	tmp = ft_memalloc(BUFF);
	counter = 0;
	while ((read(0, tmp, BUFF)) > 0)
	{
		counter++;
		if (counter == 1)
			full = ft_strdup(tmp);
		else
		{
			str = full;
			full = ft_strjoin(full, tmp);
			free(str);
		}
	}
	free(tmp);
	return (full);
}

void	ft_parse_info(t_ssl *ssl, t_info *info, char *str)
{
	t_info	*c_info;
	t_info	*new;

	new = (t_info*)malloc(sizeof(t_info));
	new->next = NULL;
	if (ssl->is_string && ssl->is_string != ssl->str_count + 1)
	{
		new->data = str;
		new->type = 2;
		ssl->is_string++;
		new->info_len = ft_strlen(str);
	}
	else
	{
		new->data = ft_parse_file(str, ssl, new);
		new->type = 3;
		new->file = ft_strdup(str);
		ssl->is_file = 0;
	}
	c_info = info;
	while (c_info->next)
		c_info = c_info->next;
	c_info->next = new;
}

void	ft_try_echo(t_info *info)
{
	t_info	*c_info;
	t_info	*new;

	new = (t_info*)malloc(sizeof(t_info));
	new->next = NULL;
	new->data = ft_parse_echo();
	new->type = 1;
	new->info_len = ft_strlen(new->data);
	if (!new->data)
		return ;
	c_info = info;
	while (c_info->next)
		c_info = c_info->next;
	c_info->next = new;
}
