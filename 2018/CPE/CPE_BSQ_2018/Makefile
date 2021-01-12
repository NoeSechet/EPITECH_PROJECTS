##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	=	bsq

SRC	=	fill_struct.c\
		initiate_clone.c\
		utils.c\
		main.c\
		final_square.c\
		clean_buf.c\

all:	$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -I./include -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all