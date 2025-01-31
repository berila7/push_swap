/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 11:12:42 by mberila          ###   ########.fr       */
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
	t_stack	*stack_a;

	stack_a = init_stack();

    if (!stack_a)
    {
        printf("Stack initialization failed\n");
        return (1);
    }

   // Test Case 1: Empty stack
    printf("\nTest Case 1: Empty stack\n");
    sa(stack_a);
    print_stack(stack_a);

    // Test Case 2: Single element
    printf("\nTest Case 2: Single element\n");
    push_to_stack(stack_a, 42);
    print_stack(stack_a);
    sa(stack_a);
    print_stack(stack_a);

    // Test Case 3: Two elements
    printf("\nTest Case 3: Two elements\n");
    push_to_stack(stack_a, 21);
    print_stack(stack_a);
    sa(stack_a);
    printf("After sa: ");
    print_stack(stack_a);

     // Test Case 4: Three elements
    printf("\nTest Case 4: Three elements\n");
    push_to_stack(stack_a, 33);
    print_stack(stack_a);
    sa(stack_a);
    printf("After sa: ");
    print_stack(stack_a);

    // Free the stack (we'll implement proper free functions later)
    free(stack_a);
    return (0);
}
