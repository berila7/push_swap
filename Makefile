NAME		=	push_swap
CHECKER		=	checker

LIBFT_DIR	=	lib/libft
GNL_DIR		=	lib/get_next_line

LIBFT		= 	$(LIBFT_DIR)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	mandatory/main.c \
				mandatory/stack_utils.c \
				mandatory/operations/swap.c \
				mandatory/operations/push.c \
				mandatory/operations/rotate.c \
				mandatory/operations/reverse_rotate.c \
				mandatory/input_validation.c \
				mandatory/sort_small.c \
				mandatory/sort_larg.c \
				mandatory/cleanup.c \

BONUS_SRCS 	=	bonus/checker_bonus.c \
            	bonus/stack_utils_bonus.c \
            	bonus/operations/swap_bonus.c \
            	bonus/operations/push_bonus.c \
            	bonus/operations/rotate_bonus.c \
            	bonus/operations/reverse_rotate_bonus.c \
            	bonus/input_validation_bonus.c \
            	bonus/cleanup_bonus.c \
            	bonus/process_operations_bonus.c \
				$(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c \

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all: $(LIBFT_DIR) $(NAME)
bonus: $(LIBFT_DIR) $(CHECKER)

$(LIBFT_DIR):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)

%.o: %.c $(LIBFT_DIR) includes/push_swap.h includes/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: $(LIBFT_DIR)