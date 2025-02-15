/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:07:58 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 09:51:48 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || !stack_b->top)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_a->top)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->size--;
	temp->next = stack_b->top;
	stack_b->top = temp;
	stack_b->size++;
}
