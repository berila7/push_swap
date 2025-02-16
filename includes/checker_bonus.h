/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:48 by mberila           #+#    #+#             */
/*   Updated: 2025/02/16 15:32:59 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_instruction
{
    char                *operation;
    struct s_instruction *next;
}   t_instruction;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;	

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
t_node	*create_new_node(int value);
t_instruction    *new_instruction(char *operation);

int		push_to_stack(t_stack *stack, int value);
int		process_args(int ac, char **av, t_stack *stack_a);
int		fill_stack(t_stack *stack_a, int *temp_array, int count);
int		is_sorted(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		convert_to_array(char **numbers, int **arr, int *count);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

/* Validation */
int		has_duplicates(int *numbers, int size);
int		is_within_int_limits(char *str);
int		is_valid_number(char *str);
int     is_valid_instruction(char *line);

/* Instructions handling */
void    process_operations(t_stack *a, t_stack *b);
int     execute_operation(t_stack *a, t_stack *b, char *op);
void    free_instructions(t_instruction *head);

/* Memory management */
void	free_stack(t_stack *stack);
void	free_split(char	**numbers);
void	clean_exit(t_stack *stack_a, t_stack *stack_b);

/* Stack operations */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack	*stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif