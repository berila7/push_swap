/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/02/18 14:22:27 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	clean_exit(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write (2, "Error\n", 6);
	exit(1);
}

static t_stack	*initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = init_stack();
	if (!*stack_a)
		return (NULL);
	*stack_b = init_stack();
	if (!*stack_b)
	{
		free_stack(*stack_a);
		return (NULL);
	}
	return (*stack_a);
}

void	f(void)
{
	system ("leaks checker");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	atexit(f);
	if (ac == 1)
		return (0);
	if (!initialize_stacks(&stack_a, &stack_b))
		clean_exit(stack_a, stack_b);
	if (!process_args(av + 1, stack_a) || has_duplicates_in_stack(stack_a))
		clean_exit(stack_a, stack_b);
	process_operations(stack_a, stack_b);
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
