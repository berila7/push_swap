#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

t_node	*create_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
int	push_to_stack(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = create_new_node(value);
	if (!node)
		return (0);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
	return (1);
}
