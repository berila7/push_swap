/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:55:12 by mberila           #+#    #+#             */
/*   Updated: 2025/02/18 17:30:39 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

int	is_valid_instruction(char *line)
{
	if (!line)
		return (0);
	return (ft_strncmp(line, "sa\n", 3) == 0
		|| ft_strncmp(line, "sb\n", 3) == 0
		|| ft_strncmp(line, "ss\n", 3) == 0
		|| ft_strncmp(line, "pa\n", 3) == 0
		|| ft_strncmp(line, "pb\n", 3) == 0
		|| ft_strncmp(line, "ra\n", 3) == 0
		|| ft_strncmp(line, "rb\n", 3) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0
		|| ft_strncmp(line, "rra\n", 4) == 0
		|| ft_strncmp(line, "rrb\n", 4) == 0
		|| ft_strncmp(line, "rrr\n", 4) == 0);
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
	int		j;
	char	**nums;

	i = 0;
	while (args[i])
	{
		nums = ft_split(args[i], ' ');
		if (!nums || !nums[0])
			return (free_split(nums), 0);
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]) || !is_within_int_limits(nums[j]))
				return (free_split(nums), 0);
			if (!push_to_stack(stack_a, ft_atoi(nums[j])))
				return (free_split(nums), 0);
			j++;
		}
		free_split(nums);
		i++;
	}
	return (1);
}
