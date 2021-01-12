##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compiles the .c stuff right ?
##

SRC	=	lib/my/my_strlen.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strncat.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		red_potatoes.c 		\

NAME = a.out

all: $(NAME)

$(NAME):
	gcc $(SRC) -I./include

clean: rm $(NAME)

fclean:	clean

re:	fclean