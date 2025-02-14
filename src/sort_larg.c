/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:49 by mberila           #+#    #+#             */
/*   Updated: 2025/02/09 16:24:30 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static int	get_target_position(t_stack *stack, int start, int end)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->index >= start && current->index <= end)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
	int	pos;
	int	mid;

	mid = start + ((end - start) / 2);
	while (a->size > 0)
	{
		pos = get_target_position(a, start, end);
		if (pos == -1)
			break ;
		if (pos <= a->size / 2)
		{
			while (pos--)
				ra(a);
		}
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
		if (b->top->index < mid)
			rb(b);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	while (b->size > 0)
	{
		pos = find_max_pos(b);
		size = b->size;
		if (pos <= size / 2)
		{
			while (pos--)
				rb(b);
		}
		else
		{
			while (pos++ < size)
			{
				rrb(b);
			}
		}
		pa (a, b);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk_size;
	int	chunk_start;
	int	chunks;
	int	i;

	normalize_stack(a);
	size = a->size;
	if ((size <= 100))
		chunks = 6;
	else
		chunks = 11;
	chunk_size = size / chunks;
	i = 0;
	chunk_start = 0;
	while (i < chunks)
	{
		push_chunk_to_b(a, b, chunk_start, chunk_start + chunk_size - 1);
		chunk_start += chunk_size;
		i++;
	}
	if (a->size > 0)
		push_chunk_to_b(a, b, chunk_start, size - 1);
	push_back_to_a(a, b);
}
