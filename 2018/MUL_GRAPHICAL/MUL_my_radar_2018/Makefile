##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_radar.c\
		instructions.c\
		create_shapes.c\
		read_map.c\
		new_air_tow_list.c\
		my_get_nbr.c\
		fill_aircraft_list.c\
		fill_tower_list.c\
		cut_screen.c\
		check_collision.c\
		update_tab_position.c\
		draw_towers.c\
		draw_planes.c\

NAME	=	my_radar

FLAGS	=	-Werror -Wall -W -Wextra -g3
FLAGS	+=	-I./include -lm -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(FLAGS)

clean:

fclean: clean
	rm -r $(NAME)

re: fclean all