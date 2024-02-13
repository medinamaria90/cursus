# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:25:35 by marimedi          #+#    #+#              #
#    Updated: 2024/02/13 11:13:57 by marimedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colores para formatear la salida en consola
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

NAME = push_swap
NAME_BONUS = checker

SRCS = srcs/push_swap.c srcs/split.c srcs/utils.c srcs/list_utils.c \
       srcs/process_input.c srcs/sort_three.c srcs/cost_calculations.c\
       srcs/find_positions.c srcs/movements.c srcs/operations.c srcs/free_stack.c

BONUS_SRCS = srcs_bonus/checker_bonus.c srcs_bonus/get_next_line/get_next_line.c srcs_bonus/free_stack_bonus.c \
             srcs_bonus/get_next_line/get_next_line_utils.c srcs_bonus/operations_bonus.c \
             srcs_bonus/process_input_bonus.c srcs_bonus/list_utils_bonus.c \
             srcs_bonus/split_bonus.c srcs_bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)$(NC)"
	$(CC) $(COLOR_FLAG) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "$(GREEN)Compiling $(NAME_BONUS)$(NC)"
	$(CC) $(COLOR_FLAG) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	@echo "$(YELLOW)Removing objects$(NC)"
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(RED)Removing executables$(NC)"
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

