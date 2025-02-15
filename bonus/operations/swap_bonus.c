/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:27 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 09:52:09 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;
	ft_swap(&(first->value), &(second->value));
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = first->next;
	ft_swap(&(first->value), &(second->value));
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
