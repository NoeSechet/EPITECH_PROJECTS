##
## EPITECH PROJECT, 2018
## Makefile navy
## File description:
## Makefile navy
##

SRC =	main.c					\
		is_description.c		\
		utils/*					\
		program_1.c				\
		program_2.c				\
		create_map.c			\
		is_connection.c			\
		print_maps.c			\
		player_turn.c			\
		enemy_turn.c			\
		check_error.c			\
		convert_binary_code.c	\
		send_signal.c			\
		hit_or_missed.c			\
		receive_signal.c		\
		win_conditions.c		\
		convert_int_into_pos.c	\

NAME	=	navy

FLAGS = -W -Wall -Wextra -Werror -I./include -g3

LIBS = -L./libmy_printf -lmy -L./libmy_getline -lgetline

all:	$(NAME)

$(NAME):
	make -C libmy_printf
	make -C libmy_getline
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:

fclean:	clean
	make fclean -C libmy_printf
	make fclean -C libmy_getline
	rm -f $(NAME)

re: fclean all