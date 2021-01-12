##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## for_unittest
##

SRC = pong101.c

TEST = test_my_pong.c

NAME = pong_test

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra  -o $(NAME) $(TEST) $(SRC) --coverage -lcriterion -I./include -lm

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

coverage:
	gcov -r *.gc*

execute:
	./$(NAME)

re: fclean all