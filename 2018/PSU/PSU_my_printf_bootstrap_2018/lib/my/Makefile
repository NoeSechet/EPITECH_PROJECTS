##
## EPITECH PROJECT, 2018
## makefile.lib
## File description:
## makefile.lib
##

SRC	=	utils.c			\
		disp_stdarg.c 	\
		sum_stdarg.c 	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):
	gcc -Wall -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libmy.a
	rm -f ../libmy.a

re:	fclean all