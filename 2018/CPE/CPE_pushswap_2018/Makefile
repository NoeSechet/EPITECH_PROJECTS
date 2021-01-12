##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	push_swap

SRC	=	main.c\
		utils.c\
		initiate_array_struct.c\
		operations.c\
		check_order.c\
		transform.c\

FLAGS = -W -Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I./include -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all