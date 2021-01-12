##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	my_screensaver.c\
		instructions.c\
		window_events.c\
		fill_main_struct.c\
		fill_spritext.c\
		first_anim.c\
		sec_anim.c\
		third_anim.c\
		fourth_anim.c\
		fifth_anim.c\
		utils.c\
		put_pixel.c\
		draw_line.c\
		draw_discs.c\
		draw_circle.c\

NAME = my_screensaver

INCLUDES = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -W $(SRC) -o $(NAME) -I./include $(INCLUDES)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all