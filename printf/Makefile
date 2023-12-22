# Name of the library //
NAME = libftprintf.a

# Sources //
SRCS = ft_printf.c ft_printf_utils.c

# Objects //
OBJS = $(SRCS:.c=.o)

# Compile //
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Aim of the program//
all : $(NAME)

# RULES --> TARGET: DEPENDENCES --> TAB --> RECIPE (ACTIONS) //
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
# RULE FOR CREATING THE OBJECTS
$(OBJS): %.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJS)

# Regla para limpiar todos los archivos generados (objetos y librería)
fclean: clean
	rm -f $(NAME)

# Regla para reconstruir todo el proyecto
re: fclean all
