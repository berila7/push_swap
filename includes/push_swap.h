/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:48 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 11:14:51 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;	

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
t_node	*create_new_node(int value);
int		push_to_stack(t_stack *stack, int value);
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
int		is_within_int_limits(char *str);
int		is_valid_number(char *str);
int		has_duplicates(int *numbers, int size);
int		process_args(int ac, char **av, t_stack *stack_a);
void	free_stack(t_stack *stack);
int		fill_stack(t_stack *stack_a, char **numbers);

#endif