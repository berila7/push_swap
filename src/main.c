/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:12:41 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 19:45:38 by mberila          ###   ########.fr       */
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

int main(int ac, char **av)
{
	int	i;

	if (!process_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 2)
		printf("Single string input: %s\n", av[1]);
	else
	{
		i = 1;
		while (i < ac)
		{
			printf("arg[%d]: %s\n", i, av[i]);
			i++;
		}
	}
	return (0);
}
