##
## EPITECH PROJECT, 2018
## PSU_42sh_2018
## File description:
## Makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	= ./lib/arraylist/create_delete_list.c \
	  ./lib/arraylist/manage_elem.c \
	  ./lib/linked_list/convert_list_env.c \
	  ./lib/linked_list/destroy_list.c \
	  ./lib/linked_list/fill_env_list.c \
	  ./lib/linked_list/insert_element.c \
	  ./lib/linked_list/linked_list.c \
	  ./lib/linked_list/linked_list_2.c \
	  ./lib/linked_list/new_list.c \
	  ./lib/linked_list/pop_element.c \
	  ./lib/linked_list/strlen_for_list.c \
	  ./lib/my_printf/lib_my_printf/getstr.c \
	  ./lib/my_printf/lib_my_printf/my_print_base.c \
	  ./lib/my_printf/lib_my_printf/my_print_longs.c \
	  ./lib/my_printf/lib_my_printf/my_print_special.c \
	  ./lib/my_printf/lib_my_printf/my_prints_basics.c \
	  ./lib/my_printf/lib_my_printf/utils.c \
	  ./lib/my_printf/src_my_printf/call_format.c \
	  ./lib/my_printf/src_my_printf/call_format_u.c \
	  ./lib/my_printf/src_my_printf/check_str.c \
	  ./lib/my_printf/src_my_printf/mod_1.c \
	  ./lib/my_printf/src_my_printf/mod_2.c \
	  ./lib/my_printf/src_my_printf/my_printf.c \
	  ./lib/utils_functions/char_in_str.c \
	  ./lib/utils_functions/create_arg_tab.c \
	  ./lib/utils_functions/create_arg_tab_utils.c \
	  ./lib/utils_functions/create_arg_tab_utils2.c \
	  ./lib/utils_functions/find_redic_pip_and_or.c \
	  ./lib/utils_functions/free_vars_tabs.c \
	  ./lib/utils_functions/fusion.c \
	  ./lib/utils_functions/get_nb_str_array.c \
	  ./lib/utils_functions/get_next_line.c \
	  ./lib/utils_functions/my_realloc_2d.c \
	  ./lib/utils_functions/my_str_to_word_array.c \
	  ./lib/utils_functions/my_strcat.c \
	  ./lib/utils_functions/my_strcmp.c \
	  ./lib/utils_functions/my_strcopy.c \
	  ./lib/utils_functions/my_strdup.c \
	  ./lib/utils_functions/strclean.c \
	  ./lib/utils_functions/strclean_spe.c \
	  ./lib/utils_functions/strcopy_pos.c \
	  ./lib/utils_functions/tab_functions.c \
	  ./lib/utils_functions/bubblesort_list.c \
	  ./main.c \
	  ./src/shell.c \
	  ./src/bin_tree/add_new_opera_node.c \
	  ./src/bin_tree/complete_tree.c \
	  ./src/bin_tree/create_new_node.c \
	  ./src/bin_tree/destroy_tree.c \
	  ./src/bin_tree/detect_opera.c \
	  ./src/bin_tree/opera_separa.c \
	  ./src/bin_tree/print_tree.c \
	  ./src/builtins/alias/exec_alias.c \
	  ./src/builtins/alias/my_alias.c \
	  ./src/builtins/alias/my_unalias.c \
	  ./src/builtins/alias/alias_loop.c \
	  ./src/builtins/cd/cd.c \
	  ./src/builtins/cd/change_env.c \
	  ./src/builtins/cd/error_handel_cd.c \
	  ./src/builtins/echo/echo_dollars.c \
	  ./src/builtins/echo/echo_error.c \
	  ./src/builtins/echo/echo_is_function.c \
	  ./src/builtins/echo/get_flags.c \
	  ./src/builtins/echo/my_echo.c \
	  ./src/builtins/env/my_env.c \
	  ./src/builtins/env_loc/display_env_loc.c \
	  ./src/builtins/env_loc/my_set.c \
	  ./src/builtins/env_loc/my_unset.c \
	  ./src/builtins/env_loc/sep_to_array.c \
	  ./src/builtins/env_loc/change_var.c \
	  ./src/builtins/env_loc/sort_list_pieces.c \
	  ./src/builtins/env_loc/is_arg_spaced.c \
	  ./src/builtins/exit/exit.c \
	  ./src/builtins/foreach/error_foreach.c \
	  ./src/builtins/foreach/my_foreach.c \
	  ./src/builtins/history/history.c \
	  ./src/builtins/repeat/error_repeat.c \
	  ./src/builtins/repeat/my_repeat.c \
	  ./src/builtins/setenv/change_values_setenv.c \
	  ./src/builtins/setenv/check_values.c \
	  ./src/builtins/setenv/exec_setenv.c \
	  ./src/builtins/setenv/setenv.c \
	  ./src/builtins/unsetenv/unsetenv.c \
	  ./src/builtins/which/my_which.c \
	  ./src/builtins/which/checks_which.c \
	  ./src/builtins/where/checks_where.c \
	  ./src/builtins/where/my_where.c \
	  ./src/check_input_errors.c \
	  ./src/check_input_errors2.c \
	  ./src/check_signals.c \
	  ./src/environment/creat_env.c \
	  ./src/environment/init_env.c \
	  ./src/execution/exec_1.c \
	  ./src/execution/check_var_inter.c \
	  ./src/execution/exec_double_redirection.c \
	  ./src/execution/exec_or_and_and.c \
	  ./src/execution/exec_pipe.c \
	  ./src/execution/exec_redir_left_and_right.c \
	  ./src/execution/execution.c \
	  ./src/execution/find_builtins.c \
	  ./src/execution/my_fork.c \
	  ./src/execution/my_globbings.c \
	  ./src/move_cursor/control_arrows.c \
	  ./src/move_cursor/move_cursor.c \
	  ./src/move_cursor/move_cursor_2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_mysh/
CFLAGS += -Wall -Wextra -W

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
