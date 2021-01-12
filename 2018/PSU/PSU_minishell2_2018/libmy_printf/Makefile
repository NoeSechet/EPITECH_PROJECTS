##
## EPITECH PROJECT, 2018
## makefile.lib
## File description:
## makefile.lib
##

SRC	=	my_printf.c\
		pointed_functions.c\
		pointed_functions_2.c\
		pointed_functions_3.c\
		padder_functions.c\
		padder_functions_2.c\
		zero_padder_functions.c\
		zero_padder_functions_2.c\
		utils.c\
		utils_parser.c\
		list_put_nbr.c\
		list_put_nbr_2.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)	clean

$(NAME):
	gcc -Wall -Wextra -Werror -W -c $(SRC) -I./include_printf
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all