##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 101pong
##

SRC    =	main.c											\
			utils/*.c										\
			function_init/*.c								\
			function_graph/*.c								\
			function_create_graph/*.c						\
			function_graph/complete_graph/*.c				\
			path_finding/*.c								\

NAME    =    lem_in

FLAGS	=	-W -Wall -Wextra
FLAGS   +=  -I./include_lem_in

LIBS = -L./libmy_printf -lmy

all:    $(NAME)

$(NAME):
	make -C libmy_printf
	gcc $(SRC) -o $(NAME) $(FLAGS) $(LIBS)

clean:

fclean: clean
	make fclean -C libmy_printf
	rm -f $(NAME)

re:    fclean all