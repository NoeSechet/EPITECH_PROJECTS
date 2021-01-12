##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

NAME	= my_nm

CC	= gcc

RM	= rm -f

SRCS	= 	./main.c \
			./get_sym_type.c \
			./get_symb.c \
			./utils.c \
			./sort_symb_list.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_nm
CFLAGS += -Wall -Wextra

all: $(NAME)
	mv $(NAME) ../

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
