# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 11:33:47 by amurakho          #+#    #+#              #
#    Updated: 2018/10/04 11:33:48 by amurakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC =	src/main.c \
		src/manage256.c \
		src/manage512.c \
		src/md5.c \
		src/padding_bits.c \
		src/parse.c \
		src/print_full.c \
		src/print_hash.c \
		src/sha256.c \
		src/sha512.c \
		src/what_func.c	\
		src/parse_flag.c

FLAGS =  -I ./inc
# FLAGS = -Wall -Wextra -Werror -I ./inc

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c -o $@ $^

$(NAME): $(OBJ)
	@make -C ./libft all
	@make -C ./ft_printf all
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a ft_printf/libftprintf.a
	@echo "Done!"

clean:
	/bin/rm -f $(OBJ)
	@make -C ./libft clean
	@make -C ./ft_printf clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./ft_printf fclean

re: fclean all

