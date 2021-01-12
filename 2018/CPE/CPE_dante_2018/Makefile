##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 101pong
##

NAME    =    my_dante

FLAGS	=  -W -Wall -Wextra -g3

all:    $(NAME)

$(NAME):
	make -C solver
	make -C generator

clean:
	rm -f *.o

fclean: clean
	make fclean -C solver
	make fclean -C generator

re:    fclean all