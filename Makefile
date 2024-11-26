NAME = libftprintf.a
LIBFT_DIR = ./libft
SOURCES = ft_printf.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_strchr.c 
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:clean
	rm -f $(NAME)

main:main.c $(SOURCES) $(NAME)
	cc -o main main.c $(NAME)
re: fclean $(NAME)

.PHONY:	all clean fclean re