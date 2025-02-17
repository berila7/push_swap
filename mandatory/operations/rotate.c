/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:51:23 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 11:21:54 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack, char *msg)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	if(msg)
		write (1, msg, 3);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a, "ra\n");
}
void	rb(t_stack *stack_b)
{
	rotate(stack_b, "rb\n");
}

void	rr(t_stack	*stack_a, t_stack *stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	write(1, "rr\n", 3);
}
