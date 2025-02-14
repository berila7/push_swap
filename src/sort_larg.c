/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:49 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 10:50:25 by mberila          ###   ########.fr       */
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
static void	get_next_pos(t_stack *a, int min, int max, int *pos)
{
	t_node	*current;
	int		i;

	i = 0;
	*pos = -1;
	current = a->top;
	while (current)
	{
		if (current->index >= min && current->index <= max)
		{
			*pos = i;
			break ;
		}
		i++;
		current = current->next;
	}
}

static void	handle_rotation(t_stack *a, t_stack *b, int pos, int mid)
{
	if (pos <= a->size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
	pb(a, b);
	if (b->top->index < mid)
		rb(b);
}

static void	process_chunk(t_stack *a, t_stack *b, int start, int chunk_size)
{
	int	pos;
	int	end;
	int	pushed;
	int	mid;

	end = start + chunk_size - 1;
	mid = start + (chunk_size / 2);
	pushed = 0;
	while (pushed < chunk_size && a->size > 0)
	{
		get_next_pos(a, start, end, &pos);
		if (pos == -1)
			break ;
		handle_rotation(a, b, pos, mid);
		pushed++;
	}
}

static void	push_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	start;
	int	total_chunks;
	int	i;

	if (a->size <= 100)
		chunk_size = a->size / 5;
	else
		chunk_size = a->size / 11;
	total_chunks = (a->size + chunk_size - 1) / chunk_size;
	i = 0;
	start = 0;
	while (i < total_chunks)
	{
		process_chunk(a, b, start, chunk_size);
		start += chunk_size;
		i++;
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	pos;

	normalize_stack(a);
	push_chunks(a, b);
	while (b->size > 0)
	{
		pos = find_max_pos(b);
		if (pos <= b->size / 2)
			while (pos--)
				rb(b);
		else
			while (pos++ < b->size)
				rrb(b);
		pa(a, b);
	}
}