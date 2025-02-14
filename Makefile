NAME	=	push_swap
LIBFT	=	lib/libft/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I includes -I libft

SRCS	=	mandatory/main.c \
			mandatory/stack_utils.c \
			mandatory/operations/swap.c \
			mandatory/operations/push.c \
			mandatory/operations/rotate.c \
			mandatory/operations/reverse_rotate.c \
			mandatory/process_args.c \
			mandatory/input_validation.c \
			mandatory/fill_stack.c \
			mandatory/sort.c \
			mandatory/sort_small.c \
			mandatory/sort_larg.c \
			mandatory/cleanup.c \

OBJS	=	$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C lib/libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C lib/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C lib/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re