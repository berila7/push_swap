/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:56:18 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 11:55:59 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	rrotate(t_stack *stack, char *msg)
{
	t_node	*last;
	t_node	*second_to_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	second_to_last = stack->top;
	while (second_to_last->next && second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (msg)
		write(1, msg, 4);
}

void	rra(t_stack *stack_a)
{
	rrotate(stack_a, "rra\n");
}

void	rrb(t_stack *stack_b)
{
	rrotate(stack_b, "rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a, NULL);
	rrotate(stack_b, NULL);
	write(1, "rrr\n", 4);
}
