/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:56:18 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 17:50:21 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	rrotate(t_stack *stack)
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
}

void	rra(t_stack *stack_a)
{
	rrotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	rrotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
