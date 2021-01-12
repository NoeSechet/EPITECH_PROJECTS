##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	push_swap

SRC	=	bubble_sort_array.c\
		rotate_left.c\
		rotate_right.c\

FLAGS = -W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I./include -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all