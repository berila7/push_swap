/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:49:05 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 10:13:45 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (!stack->top)
		return (-1);
	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	size;

	pos = find_min_position(stack_a);
	size = stack_a->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack_a);
			pos++;
		}
	}
	pb(stack_a, stack_b);
}



void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (size == 4)
	{
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (size == 5)
	{
		push_min_to_b(stack_a, stack_b);
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
