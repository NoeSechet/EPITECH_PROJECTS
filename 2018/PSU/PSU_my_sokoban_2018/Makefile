##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_sokoban.c\
		utils.c\
		instructions.c\
		fill_player_struct.c\
		fill_player_pos.c\
		moves_functions.c\
		nbr_line.c\
		fill_layer.c\
		print_layer.c\
		detect_o_pos.c\
		detect_x_pos.c\
		reset.c\
		win_lose_cond.c\

NAME	=	my_sokoban

FLAGS	=	-Wall -Werror -Wextra -W -g3

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME) -I./include -lncurses

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all