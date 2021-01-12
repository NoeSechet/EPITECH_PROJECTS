##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 101pong
##

SRC    =	main.c									\
			strcopy.c								\
			special_str_tab.c						\
			my_strlen.c								\
			get_maze.c								\
			dijkstra.c								\
			init_function.c							\
			update_path.c							\
			get_position.c							\
			get_width_height.c						\

NAME    =    solver

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