##
## EPITECH PROJECT, 2020
## PSU_2019_malloc
## File description:
## Makefile
##

NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= ./free.c\
	./malloc.c\
	./calloc.c\
	./realloc.c\
	./reallocarray.c\
	./utils.c\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -fPIC -Wall -Wextra -Werror -I./

all: $(NAME)

$(NAME): $(OBJS)
	gcc -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
