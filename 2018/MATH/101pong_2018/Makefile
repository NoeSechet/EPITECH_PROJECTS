##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = pong101.c

NAME = 101pong

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -W $(SRC) -o $(NAME) -I./include -lm

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all