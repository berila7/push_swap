/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:33:58 by mberila           #+#    #+#             */
/*   Updated: 2025/02/14 17:14:50 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	convert_to_array(char **numbers, int **arr, int *count)
{
	int	i;

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

int	fill_stack(t_stack *stack_a, int *temp_array, int count)
{
	int	result;
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		result = push_to_stack(stack_a, temp_array[i]);
		i--;
	}
	free(temp_array);
	return (result);
}
