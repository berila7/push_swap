NAME	=	push_swap
LIBFT	=	lib/libft/libft.a
CHECKER =	checker

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

BONUS_SRCS = bonus/checker_bonus.c \
             bonus/stack_utils_bonus.c \
             bonus/operations/swap_bonus.c \
             bonus/operations/push_bonus.c \
             bonus/operations/rotate_bonus.c \
             bonus/operations/reverse_rotate_bonus.c \
             bonus/process_args_bonus.c \
             bonus/input_validation_bonus.c \
             bonus/fill_stack_bonus.c \
             bonus/cleanup_bonus.c \
             bonus/process_operations_bonus.c \
			 lib/get_next_line/get_next_line.c \
			 lib/get_next_line/get_next_line_utils.c \

OBJS	=	$(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(CHECKER)

$(LIBFT):
	@make -C lib/libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%_bonus.o: %_bonus.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C lib/libft clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C lib/libft fclean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re