# Name of the library //
NAME = libftprintf.a
# Sources //
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
