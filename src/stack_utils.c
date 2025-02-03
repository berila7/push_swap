/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:38 by mberila           #+#    #+#             */
/*   Updated: 2025/02/03 11:15:50 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

t_node	*create_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

int	push_to_stack(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = create_new_node(value);
	if (!node)
		return (0);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
int	find_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		pos;
	int		max_pos;

	current = stack->top;
	max_index = current->index;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}
