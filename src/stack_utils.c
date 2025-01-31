#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	return (stack);
}

t_node	*create_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 2;
	node->next = NULL;
}
int	push_to_stack(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	stack->top = node;
	stack->size = 1;
}
