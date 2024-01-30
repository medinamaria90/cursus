# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:25:35 by marimedi          #+#    #+#              #
#    Updated: 2024/01/29 13:26:05 by marimedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = srcs/push_swap.c srcs/split.c srcs/split_utils.c srcs/list_utils.c \
       srcs/manage_input.c srcs/sort_three.c srcs/cost_calculations.c \
       srcs/find_positions.c srcs/movements.c srcs/operations.c

BONUS_SRCS = srcs/checker.c srcs/ft_strncmp.c srcs/get_next_line.c \
             srcs/get_next_line_utils.c srcs/operations.c srcs/manage_input.c \
             srcs/list_utils.c srcs/split.c srcs/split_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

