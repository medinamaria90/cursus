# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:22:06 by marimedi          #+#    #+#              #
#    Updated: 2024/01/09 11:09:44 by marimedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_int_to_hex.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: $(OBJS) $(NAME)
$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
