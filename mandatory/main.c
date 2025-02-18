/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/02/18 10:56:29 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_exit(t_stack *stack_a, t_stack *stack_b)
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	print_stack(stack_a, "Stack A before sorting");
    print_stack(stack_b, "Stack B before sorting");
	if (size == 2)
	{
		sa(stack_a);
		print_stack(stack_a, "Stack A after sa");
	}
	else if (size == 3)
	{
		sort_three(stack_a);
		print_stack(stack_a, "Stack A after sort_three");
	}
	else if (size <= 5)
	{
		sort_small(stack_a, stack_b);
		print_stack(stack_a, "Stack A after sort_small");
        print_stack(stack_b, "Stack B after sort_small");
	}
	else
	{
		sort_large(stack_a, stack_b);
		print_stack(stack_a, "Stack A after sort_large");
        print_stack(stack_b, "Stack B after sort_large");
	}
}

// void	f(void)
// {
// 	system ("leaks push_swap");
// }

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// atexit(f);
	if (ac < 2)
		return (0);
	if (!initialize_stacks(&stack_a, &stack_b))
		clean_exit(stack_a, stack_b);
	if (!process_args(ac, av, stack_a))
		clean_exit(stack_a, stack_b);
		// Debug print after initialization
    print_stack(stack_a, "Stack A after initialization");
    print_stack(stack_b, "Stack B after initialization");
	if (!is_sorted(stack_a))
	{
		sort_stack(stack_a, stack_b);
		print_stack(stack_a, "Stack A after sorting");
        print_stack(stack_b, "Stack B after sorting");
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
