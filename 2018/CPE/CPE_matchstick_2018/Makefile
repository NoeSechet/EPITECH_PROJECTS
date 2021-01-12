##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	=	matchstick

SRC	=	main.c\
		fill_board.c\
		my_get_nbr.c\
		utils.c\
		print_board.c\
		player_interaction.c\
		errors.c\
		artificial_int_play.c\
		finishing_artificial_play.c\

all:	$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -I/.include -g3

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all