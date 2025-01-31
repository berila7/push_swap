#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int		tmp;
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || !stack_a->top, !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = stack_a->top->next;

	ft_swap(&first, &second);
	write(1, "sa\n", 3);
}