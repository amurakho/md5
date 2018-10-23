/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:08:05 by amurakho          #+#    #+#             */
/*   Updated: 2018/07/12 03:08:08 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <zconf.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <wchar.h>

int		ft_printw(wchar_t *str, int accept);
int		ft_makewwidht(wchar_t *str, int **full);
int		ft_findsymbol(wchar_t *str, int **full, char *symbol);
void	ft_ifnzero(char **str, int *counter, int *format);
void	ft_ifplusminus(char **str, int *format, int *counter, int *spaces);
int		ft_printwstr(wchar_t *new_str, char *old, int **full);
int		workingformat(char *format_str, size_t len, va_list args, char *str);
int		makeformatstr(const char **format, int counter, va_list args);
int		ft_parse(char type, int **full, va_list args, char *str);
int		workingformat(char *format_str, size_t len, va_list args, char *str);
int		pf_putstr(const char *str);
int		ft_makewstr(wchar_t *str, int **full, char *old);
wchar_t	*pf_strncpy(wchar_t *destptr, const wchar_t *srcptr, int num);
int		ft_makestrwidth(char *str, int *modificators, int *format, char type);
int		ft_findnumber(char *format_str, int *start);
int		*ft_modificators(int *modificators, char *format_str, va_list args);
int		ft_printf(const char *format, ...);
char	*my_itoa_base(intptr_t num, int base, int is_bigger);
char	*printmemory(va_list args);
char	*upreparetosize(int flag, va_list args, char type);
char	*preparetosize(int flag, va_list args, char type);
char	*makebase(char type, intmax_t number);
int		*ft_findformat(char *format_str, int *format);
size_t	pf_strlen(wchar_t *str);
int		ft_findflag(char *format_str, char *base);
int		ft_makeprintbl(char *str, int **full, char type);
int		ft_makeaccept(char *old, int **full, char type);
int		fz(char *str);
int		ft_makewidthx(char **str, int *format, char symbol, int spaces);
int		ft_ifnformat(char *str, int *format, int spaces, char symbol);
int		ft_ifnotint(char *str, int *format, char symbol, int spaces);
int		ft_parsetype(char *str, int **full, char type);
int		ft_ifformat(char *str, int *format, int spaces, char symbol);
int		ft_makestrwwidth(char *str, int spaces, int *format, char type);
int		ft_makewprintbl(char *str, int **full, char type);
char	*ft_makeuni(wint_t code, char *new_str);
char	*ft_makewchar(wchar_t symbol);
int		ft_makestrwidth(char *str, int *modificators, int *format, char type);
int		ft_makeptr(char *str, int **full, char type);
int		ft_makeprintstr(char *str, int **full, char type);
int		ft_makediff(char type, int **full, va_list args);
char	*my_itoa_basemax(uintmax_t num, size_t base, int is_bigger);
char	*ft_itoamax(intmax_t n);
#endif
