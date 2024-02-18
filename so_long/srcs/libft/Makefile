
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
ORANGE=\033[0;33m
NC=\033[0m

# Name of the library //
NAME = libft.a

# Sources //
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
       ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c \
	   ft_count_char_in_str.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	      ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

# Objects //
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Compile //
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Aim of the program//

all : $(NAME)
	@echo "$(GREEN)----->> Creating library: $(NAME)$(NC)"

# Bonus rule
bonus: $(OBJS) $(BONUS_OBJS)
	@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	@ranlib $(NAME)

# RULES --> TARGET: DEPENDENCES --> TAB --> RECIPE (ACTIONS) //
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
# RULE FOR CREATING THE OBJECTS
$(OBJS): %.o : %.c libft.h
	@echo "$(YELLOW)Creating $@"
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(ORANGE)Removing object files"

# Regla para limpiar todos los archivos generados (objetos y librería)
fclean: clean
	@rm -f $(NAME) $(BONUS_OBJS)
	@echo "$(ORANGE)Removing all the created files"

# Regla para reconstruir todo el proyecto
re: fclean all
