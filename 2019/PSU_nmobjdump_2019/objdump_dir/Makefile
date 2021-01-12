##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

NAME	= my_objdump

CC	= gcc

RM	= rm -f

SRCS	=	./main.c \
			./print_flag_error.c \
			./print_usage.c \
			./launch.c \
			./get_f_info.c \
			./get_s_info.c \
			./get_f_s_info.c \
			./get_map.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_objd/
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
