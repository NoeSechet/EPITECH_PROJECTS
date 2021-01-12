##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	minishell.c							\
		utils_functions/*.c					\
		utils_mini2/*.c						\
		env_copy.c							\
		bin_tree/*.c						\
		function_commands/*.c				\
		linked_list/*.c						\
		functions_opera/*.c					\
		analyse_command.c					\
		pwd_manager.c						\
		execute_binary.c					\
		destroy_tab.c						\
		check_com_exist.c					\


NAME	=	mysh

FLAGS = -W -Wall -Wextra -g3

LIBS = -L./libmy_printf -lmy

all:	$(NAME)

$(NAME):
	make -C libmy_printf
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBS) -I./include_mini2 -g3

clean:

fclean:	clean
	make fclean -C libmy_printf
	rm -rf $(NAME)

re:	fclean all