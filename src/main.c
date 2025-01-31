/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 12:44:42 by mberila          ###   ########.fr       */
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

int main(void)
{
	t_stack *stack_a;
    t_stack *stack_b;
    
    // Initialize stacks
    stack_a = init_stack();
    stack_b = init_stack();
    
    // Test push operations
    printf("Initial state:\n");
    push_to_stack(stack_a, 1);
    push_to_stack(stack_a, 2);
    push_to_stack(stack_a, 3);
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);
    
    // Test pb
    printf("\nTesting pb:\n");
    pb(stack_a, stack_b);
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);
    
    // Test pa
    printf("\nTesting pa:\n");
    pa(stack_a, stack_b);
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    // Free memory
    free(stack_a);
    free(stack_b);
    return (0);
}
