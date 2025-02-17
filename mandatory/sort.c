/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:33:19 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 10:58:43 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->top->value;
	mid = stack->top->next->value;
	bot = stack->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(stack);
	else if (top > mid && mid > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack);
}
