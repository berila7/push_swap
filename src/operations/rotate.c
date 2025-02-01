/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:51:23 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 10:55:06 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	first = stack_a->top;
	stack_a->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);	
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if(!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	first = stack_b->top;
	stack_b->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack	*stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_a && stack_a->top && stack_a->top->next)
	{
		last = stack_a->top;
		while (last->next)
			last = last->next;
		first = stack_a->top;
		stack_a->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (stack_b && stack_b->top && stack_b->top->next)
	{
		last = stack_b->top;
		while (last->next)
			last = last->next;
		first = stack_b->top;
		stack_b->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}