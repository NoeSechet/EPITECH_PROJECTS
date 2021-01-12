NAME	= 	libasm.so

CC	= 	ld

RM	= 	rm -f

SRCS	=	strlen.asm \
			strchr.asm \
			strcmp.asm \
			strncmp.asm \
			memcpy.asm \
			memset.asm \
			strcasecmp.asm \
			rindex.asm \
			strcspn.asm \

OBJS	=	$(SRCS:.asm=.o)

CFLAGS	=	-fpic -shared

ASM	= 	nasm

ASMFLAGS	=	-f elf64

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re