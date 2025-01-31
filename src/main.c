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

	stack_a = init_stack();
    if (!stack_a)
    {
        printf("Stack initialization failed\n");
        return (1);
    }

    // Test pushing some numbers
    printf("Testing stack operations:\n");
    print_stack(stack_a);  // Should print empty stack

    push_to_stack(stack_a, 42);
    print_stack(stack_a);  // Should print: 42

    push_to_stack(stack_a, 21);
    print_stack(stack_a);  // Should print: 21 42

    push_to_stack(stack_a, 33);
    print_stack(stack_a);  // Should print: 33 21 42

    // Free the stack (we'll implement proper free functions later)
    free(stack_a);
    return (0);
}
