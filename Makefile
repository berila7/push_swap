NAME	=	push_swap
LIBFT	=	libft/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I includes -I libft

SRCS	=	src/main.c \
			src/stack_utils.c \
			src/operations/swap.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/process_args.c \
			src/input_validation.c \
			src/fill_stack.c \
			src/sort.c \

OBJS	=	$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re