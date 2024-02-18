# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#              #
#    Updated: 2024/02/18 17:47:23 by marimedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -g
LIBFT_PATH = srcs/libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
ORANGE=\033[0;91m
NC=\033[0m

SRCS =  srcs/check_map.c srcs/process_map.c srcs/so_long.c \
		srcs/flood_field.c srcs/ft_error.c\

OBJS = $(SRCS:.c=.o)

all:
	@echo " ------------->>> SO_LONG <<<------------$(NC)"
	@echo " "
	@make dependencies 
	@make $(NAME)

	
%.o : %.c
	@echo "$(CYAN)Creating $@ file"
	@$(CC) $(CFLAGS) -c -o $@ $<

dependencies:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	@echo "Compiling $(NAME) objects $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	@echo "$(YELLOW)Removing objects$(NC)"
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "$(YELLOW)Removing executables$(NC)"
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

