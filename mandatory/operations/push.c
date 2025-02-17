/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:07:58 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 11:32:15 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *dst, t_stack *src, char *msg)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	src->size--;
	temp->next = dst->top;
	dst->top = temp;
	dst->size++;
	write(1, msg, 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a, "pb\n");
}
