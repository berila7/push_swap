/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 13:42:39 by mberila          ###   ########.fr       */
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
    
    // Add elements to stack A
    push_to_stack(stack_a, 1);
    push_to_stack(stack_a, 2);
    push_to_stack(stack_a, 3);
    push_to_stack(stack_a, 4);
    
    // Add elements to stack B
    push_to_stack(stack_b, 10);
    push_to_stack(stack_b, 20);
    push_to_stack(stack_b, 30);
    push_to_stack(stack_b, 40);

    printf("Initial state:\n");
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    // Test rra
    printf("\nTesting rra:\n");
    rra(stack_a);
    printf("Stack A: ");
    print_stack(stack_a);

    // Test rrb
    printf("\nTesting rrb:\n");
    rrb(stack_b);
    printf("Stack B: ");
    print_stack(stack_b);

    // Test rrr
    printf("\nTesting rrr:\n");
    rrr(stack_a, stack_b);
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    // Free memory
    free(stack_a);
    free(stack_b);
    return (0);
}
