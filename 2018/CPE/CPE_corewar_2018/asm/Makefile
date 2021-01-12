##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= asm

CC	= gcc

RM	= rm -f

SRCS	= ./src/argument.c \
	  ./src/asm_usage.c \
	  ./src/coding_byte.c \
	  ./src/file.c \
	  ./src/get_byte.c \
	  ./src/get_data.c \
	  ./src/get_header.c \
	  ./src/get_label.c \
	  ./src/is_function.c \
	  ./src/main.c \
	  ./src/op.c \
	  ./src/check_error.c \
	  ./src/format_line.c \
	  ./src/useful_function.c \
	  ./utils/free_array.c \
	  ./utils/my_strlen.c \
	  ./utils/str_ncomp.c \
	  ./utils/strcopy.c \
	  ./utils/strcopy_spe.c \
	  ./utils/swap_endian.c \
	  ./utils/vector_free.c \
	  ./utils/vector_get.c \
	  ./utils/vector_new.c \
	  ./utils/vector_pop.c \
	  ./utils/vector_push.c \
	  ./utils/str_to_word_array.c \
	  ./utils/str_clean.c \
	  ./utils/strcopy_pos.c \
	  ./utils/cat.c \
	  ./utils/vector_realloc.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/ -g3
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re