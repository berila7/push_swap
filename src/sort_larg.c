/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:49 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 19:49:13 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_bits;

	if (!stack->top)
		return (0);
	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	normalize_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = stack->top;
	while (current)
	{
		rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	j;
	int	size;
	int	max_bits;

	normalize_stack(stack_a);
	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	bit = 0;
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((stack_a->top->index >> bit) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		bit++;
	}
}
