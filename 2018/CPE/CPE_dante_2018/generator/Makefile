##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 101pong
##

SRC    =	main.c									\
			init_function/*.c						\
			stack_list/insert_move.c				\
			stack_list/remove_move.c				\
			valid_moves.c							\
			check_moves.c							\
			get_column_line.c						\
			dig_maze.c								\

NAME    =    generator

FLAGS	=  -W -Wall -Wextra -g3
FLAGS   +=  -I../include_dante

all:    $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:    fclean all