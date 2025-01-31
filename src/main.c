/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 12:14:34 by mberila          ###   ########.fr       */
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
    if (!stack_a || !stack_b)
    {
        printf("Stack initialization failed\n");
        return (1);
    }

    // Test sa
    printf("\nTesting sa:\n");
    push_to_stack(stack_a, 1);
    push_to_stack(stack_a, 2);
    push_to_stack(stack_a, 3);
    print_stack(stack_a);
    sa(stack_a);
    print_stack(stack_a);

    // Test sb
    printf("\nTesting sb:\n");
    push_to_stack(stack_b, 10);
    push_to_stack(stack_b, 20);
    push_to_stack(stack_b, 30);
    print_stack(stack_b);
    sb(stack_b);
    print_stack(stack_b);

    // Test ss
    printf("\nTesting ss:\n");
    print_stack(stack_a);
    print_stack(stack_b);
    ss(stack_a, stack_b);
    printf("After ss:\n");
    print_stack(stack_a);
    print_stack(stack_b);

    // Free memory
    free(stack_a);
    free(stack_b);
    return (0);
}
