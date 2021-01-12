##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main.c\
		utils.c\


NAME	=	rostring

all:	$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -W $(SRC) -o $(NAME) -I./include

clean:

fclean:	clean
	rm -f $(NAME)

re:	fclean all
