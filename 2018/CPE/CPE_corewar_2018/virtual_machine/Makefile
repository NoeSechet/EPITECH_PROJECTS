##
## EPITECH PROJECT, 2018
## CPE_corewar_2018
## File description:
## Makefile
##

NAME	= corewar

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./../rsc/op.c \
	  ./src/my_put_nbr_base.c \
	  ./src/machine_functions/add_sub.c \
	  ./src/machine_functions/aff.c \
	  ./src/machine_functions/and_or_xor.c \
	  ./src/machine_functions/fork_lfork.c \
	  ./src/machine_functions/ld_lld.c \
	  ./src/machine_functions/ldi_lldi.c \
	  ./src/machine_functions/live.c \
	  ./src/machine_functions/st.c \
	  ./src/machine_functions/sti.c \
	  ./src/machine_functions/zjmp.c \
	  ./src/stock_prog.c \
	  ./src/utils.c \
	  ./src/utils_bis.c \
	  ./src/my_get_nbr.c \
	  ./src/arraylist.c \
	  ./src/detect_functions.c \
	  ./src/available_id.c \
	  ./src/check_errors.c \
	  ./src/init_functions.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_corewar/
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
