##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	flag.c\
		fusion.c\
		ls_utils.c\
		l_flag.c\
		simple_l_flag.c\
		l_error_function.c\
		d_flag.c\
		t_flag.c\
		l_list.c\
		my_ls.c\
		check_presence.c\
		check_flag_struct.c\

NAME	=	my_ls

FLAGS = -W -Wall -Wextra -Werror

LIBS = -L./libmy_printf -lmy

all:	$(NAME)

$(NAME):
	make -C libmy_printf
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBS) -I./include

clean:

fclean:	clean
	make fclean -C libmy_printf
	rm -f $(NAME)

re:	fclean all