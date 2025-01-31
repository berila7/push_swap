/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:52 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 12:34:18 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;

	ft_swap(&(first->value), &(second->value));
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (stack_a && stack_a->top && stack_a->top->next)
	{
		first_a = stack_a->top;
		second_a = first_a->next;
		ft_swap(&(first_a->value), &(second_a->value));
	}
	if (stack_b && stack_b->top && stack_b->top->next)
	{
		first_b = stack_b->top;
		second_b = first_b->next;
		ft_swap(&(first_b->value), &(second_b->value));
	}
	write(1, "ss\n", 3);
}
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_a;
	t_node	*top_b;

	top_a = stack_a->top;
	top_b = stack_b->top;
	push_to_stack(stack_a, top_b->value);
	stack_b->size--;
	stack_b->top->value = NULL;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_a;
	t_node	*top_b;

	top_a = stack_a->top;
	top_b = stack_b->top;
	push_to_stack(stack_b, top_a->value);
	stack_a->size--;
	stack_a->top->value = NULL;
}
