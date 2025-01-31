/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:52 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 12:57:54 by mberila          ###   ########.fr       */
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
	t_node	*temp;

	if (!stack_b || !stack_b->top)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
}
void	ra(t_stack *stack_a)
{
	t_node	*last_a;
	t_node	*temp;

	if (stack_a->size < 2)
		return ;
	last_a = stack_a->top;
	temp = stack_a->top->next;
	while (last_a)
		last_a = last_a->next;
	last_a->next = stack_a->top;
	stack_a->top = last_a;
}

void	rb(t_stack *stack_b)
{
	
	t_node	*last_a;
	t_node	*temp;

	if (stack_b->size < 2)
		return ;
	last_a = stack_b->top;
	temp = stack_b->top->next;
	while (last_a)
		last_a = last_a->next;
	last_a->next = stack_b->top;
	stack_b->top = last_a;
}

void	rr(t_stack	*stack_a, t_stack *stack_b)
{
	
}