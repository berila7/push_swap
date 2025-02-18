/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:55:12 by mberila           #+#    #+#             */
/*   Updated: 2025/02/18 13:29:58 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_within_int_limits(char *str)
{
	long	num;

	if (!str)
		return (0);
	num = ft_atoi_long(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates_in_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	process_args(char **args, t_stack *stack_a)
{
	int		i;
	int		num;
	int		j;
	char	**nums;

	i = 0;
	while (args[i])
	{
		nums = ft_split(args[i], ' ');
		if (!nums)
			return (0);
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]) || !is_within_int_limits(nums[j]))
				return (free_split(nums), 0);
			num = ft_atoi(nums[j]);
			if (!push_to_stack(stack_a, (int)num))
				return (free_split(nums), 0);
			j++;
		}
		free_split(nums);
		i++;
	}
	if (has_duplicates_in_stack(stack_a))
		return (0);
	return (1);
}

