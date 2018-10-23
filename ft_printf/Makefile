# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 13:49:03 by amurakho          #+#    #+#              #
#    Updated: 2018/07/14 13:49:05 by amurakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

LIBFT_N = 			libft.a
FT_SRC_DIR =		../libft
PRINTF_SRC_DIR =	./printf

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR)ft_printf.h

FT_COMPILED =		ft_tolower.o \
					ft_toupper.o \
					ft_isdigit.o \
					ft_isalpha.o \
					ft_isalnum.o \
					ft_isascii.o \
					ft_isprint.o \
					ft_strlen.o \
					ft_strchr.o \
					ft_strcmp.o \
					ft_strncmp.o \
					ft_strstr.o \
					ft_strnstr.o \
					ft_strcpy.o \
					ft_strncpy.o \
					ft_strdup.o \
					ft_strcat.o \
					ft_strncat.o \
					ft_strlcat.o \
					ft_memcpy.o \
					ft_memccpy.o \
					ft_memmove.o \
					ft_memcmp.o \
					ft_memset.o \
					ft_memchr.o \
					ft_bzero.o \
					ft_memalloc.o \
					ft_memdel.o \
					ft_strnew.o \
					ft_strdel.o \
					ft_strclr.o \
					ft_striter.o \
					ft_striteri.o \
					ft_strmap.o \
					ft_strmapi.o \
					ft_strequ.o \
					ft_strnequ.o \
					ft_strsub.o \
					ft_atoi.o \
					ft_strtrim.o \
					ft_strsplit.o \
					ft_itoa.o \
					ft_putchar.o \
					ft_putstr.o \
					ft_putendl.o \
					ft_putnbr.o \
					ft_putchar_fd.o \
					ft_putstr_fd.o \
					ft_putendl_fd.o \
					ft_putnbr_fd.o \
					ft_abs.o \
					ft_makenb.o \
					ft_strjoin.o \
					ft_makemem.o

PRINTF_COMPILED = 	ft_printf.o \
					make_charl.o \
					make_diff.o \
					parse_type.o \
					make_number_a.o \
					make_number_w.o \
					make_ptr.o \
					make_size.o \
					make_str.o \
					make_strl.o \
					parse_format.o \
					parse_mod.o \
					parse_spec.o \
					pf_lib1.o \
					ft_myitoabasemax.o \
					ft_itoamax.o \
					print_str.o \
					make_format_str.o \
					parse_format_str.o  \
					print_strl.o \
					do_width_strl.o \
					do_width_x.o \
					do_modificators_num.o \
					pf_lib2.o \

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@ar rc $(LIBFT_N) $(FT_COMPILED)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@rm -f $(LIBFT_N)
	@echo "fcleaned" $(NAME)

re: fclean all
