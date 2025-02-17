/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:53:27 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 11:56:22 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	swap(t_stack *stack, char *msg)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	ft_swap(&(stack->top->value), &(stack->top->next->value));
	if (msg)
		write(1, msg, 3);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a, "sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b, "sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	write(1, "ss\n", 3);
}
