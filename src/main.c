/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 10:27:21 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		printf("stack is empty\n");
		return ;
	}
	current = stack->top;
	printf("Stack (size %d): ", stack->size);
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void f(void)
{
	system ("leaks push_swap");
}

int main(int ac, char **av)
{
	t_stack *stack_a;
    t_stack *stack_b;
	
	atexit(f);
    stack_a = init_stack();
    stack_b = init_stack();
    if (!stack_a || !stack_b)
    {
		free_stack(stack_a);
		free_stack(stack_b);
        write(2, "Error\n", 6);
        return (1);
    }

    if (!process_args(ac, av, stack_a))
    {
		free_stack(stack_a);
		free_stack(stack_b);
        write(2, "Error\n", 6);
        return (1);
    }

    // Print stack for testing
    printf("Initial stack A: ");
    print_stack(stack_a);

	free_stack(stack_a);
	free_stack(stack_b);
    // Add cleanup code here
    return (0);
}
