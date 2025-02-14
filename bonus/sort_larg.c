/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:49 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 14:44:36 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	detect_pattern(t_node *tmp, int size)
{
	int	diff;
	int	count;

	count = 0;
	while (tmp && tmp->next)
	{
		diff = tmp->index - tmp->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		tmp = tmp->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

static void	normalize_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;
	int		rank;

	cur = stack->top;
	while (cur)
	{
		rank = 0;
		tmp = stack->top;
		while (tmp)
		{
			if (tmp->value < cur->value)
				rank++;
			tmp = tmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

static int	select_range(int size)
{
	if (size > 100)
		return (33);
	return (16);
}

static void	semi_sort(t_stack *a, t_stack *b, int size)
{
	int	is_comb;
	int	range;
	int	i;

	range = select_range(size);
	is_comb = detect_pattern(a->top, size);
	i = 0;
	while (i < size)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->top->index <= (i + range))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (is_comb)
			rra(a);
		else
			ra(a);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	size;

	normalize_stack(a);
	semi_sort(a, b, a->size);
	while (b->size)
	{
		max_pos = find_max_pos(b);
		if (max_pos == 0)
			pa(a, b);
		else
		{
			size = b->size;
			if (max_pos <= (size / 2))
				rb(b);
			else
				rrb(b);
		}
	}
}
