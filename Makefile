NAME = libftprintf.a

SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
clean:
	rm -f $(OBJECTS)

fclean:clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re