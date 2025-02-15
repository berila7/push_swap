/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:56:18 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 09:51:56 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*second_to_last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	second_to_last = stack_a->top;
	while (second_to_last->next && second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*second_to_last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	second_to_last = stack_b->top;
	while (second_to_last->next && second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
