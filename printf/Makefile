# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:19:57 by marimedi          #+#    #+#              #
#    Updated: 2024/01/08 19:20:16 by marimedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_int_to_hex.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
AR = ar crs
all: $(OBJS) $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
