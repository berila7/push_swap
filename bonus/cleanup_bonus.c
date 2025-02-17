/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:07:12 by mberila           #+#    #+#             */
/*   Updated: 2025/02/17 10:20:09 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_split(char	**numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

void	free_instructions(t_instruction *head)
{
	t_instruction	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->operation);
		free(temp);
	}
}
