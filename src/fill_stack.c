/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:33:58 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 10:48:34 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	convert_to_array(char **numbers, int **arr, int *count)
{
	int	i;

	*count = 0;
	while (numbers[*count])
		(*count)++;
	*arr = malloc(sizeof(int) * (*count));
	if (!*arr)
		return (0);
	i = 0;
	while (numbers[i])
	{
		(*arr)[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (1);
}

static int	push_numbers(t_stack *stack, int *numbers, int count)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		if (!push_to_stack(stack, numbers[i]))
			return (0);
		i--;
	}
	return (1);
}

int	fill_stack(t_stack *stack_a, char **numbers)
{
	int	result;
	int	*temp_array;
	int	count;

	if (!convert_to_array(numbers, &temp_array, &count))
		return (0);
	if (has_duplicates(temp_array, count))
	{
		free(temp_array);
		return (0);
	}
	result = push_numbers(stack_a, temp_array, count);
	free(temp_array);
	return (result);
}