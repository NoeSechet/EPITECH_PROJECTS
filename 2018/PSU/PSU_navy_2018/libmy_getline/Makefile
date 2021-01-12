##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libgetline.a

all:	$(NAME)	clean

$(NAME):
	gcc -Wall -Wextra -Werror -W -c $(SRC) -I./include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all