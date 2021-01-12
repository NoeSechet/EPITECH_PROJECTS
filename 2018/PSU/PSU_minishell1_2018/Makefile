##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	minishell.c\
		env_copy.c\
		special_str_tab.c\
		my_get_nbr.c\
		utils.c\
		utils_bis.c\
		utils_bis_bis.c\
		new_list.c\
		fill_env_list.c\
		insert_element.c\
		pop_element.c\
		com_cd.c\
		com_env.c\
		com_setenv.c\
		com_unsetenv.c\
		com_exec.c\
		com_exit.c\
		check_com_exist.c\
		execute_binary.c\
		destroyer.c\

NAME	=	mysh

FLAGS = -W -Wall -Wextra -Werror

LIBS = -L./libmy_printf -lmy

all:	$(NAME)

$(NAME):
	make -C libmy_printf
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBS) -I./include -g3

clean:

fclean:	clean
	make fclean -C libmy_printf
	rm -f $(NAME)

re:	fclean all