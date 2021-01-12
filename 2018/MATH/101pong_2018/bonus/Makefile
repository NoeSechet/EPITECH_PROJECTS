##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = main.c ball_draw.c draw_brick.c

NAME = bonus_pong

INCLUDES = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -W $(SRC) -o $(NAME) -I./include $(INCLUDES)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all