# General Settings
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
LIBFT_PATH := libs/libft/
LIBFT_LIB := $(LIBFT_PATH)libft.a
LIBMLX_PATH := ./libs/MLX42
LIBMLX_LIB := $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Headers and Libraries
HEADERS := -I ./includes -I $(LIBMLX_PATH)/include

# So_Long Settings
SO_LONG := so_long
SO_LONG_SRCS := srcs/check_map.c srcs/process_map.c srcs/so_long.c srcs/flood_field.c srcs/ft_error.c
SO_LONG_OBJS := $(SO_LONG_SRCS:.c=.o)

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
ORANGE := \033[0;91m
NC := \033[0m

# Rules
all: libmlx $(SO_LONG)

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

# So_Long Rules
$(SO_LONG): dependencies $(SO_LONG_OBJS)
	@echo "$(CYAN)Creating $(SO_LONG)$(NC)"
	@$(CC) $(CFLAGS) $(SO_LONG_OBJS) -o $@ $(LIBFT_LIB) $(LIBMLX_LIB) $(HEADERS)

%.o: %.c
	@echo "$(CYAN)Creating $@ file$(NC)"
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

dependencies:
	@make -C $(LIBFT_PATH) all

clean:
	@echo "$(YELLOW)Removing objects$(NC)"
	@make -C $(LIBFT_PATH) clean
	@rm -f $(SO_LONG_OBJS)

fclean: clean
	@echo "$(YELLOW)Removing executables$(NC)"
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(SO_LONG)

re: fclean all

.PHONY: all libmlx dependencies clean fclean re
