#include "../includes/push_swap.h"
#include <stdio.h>  // For printf

void    print_stack(t_stack *stack, char *name)
{
    t_node *current;
    
    printf("\n=== %s ===\n", name);
    if (!stack || !stack->top)
    {
        printf("Empty stack\n");
        return;
    }
    printf("Size: %d\n", stack->size);
    printf("Contents: ");
    current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n==========\n");
}