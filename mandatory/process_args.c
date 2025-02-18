/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:55:09 by mberila           #+#    #+#             */
/*   Updated: 2025/02/18 11:57:24 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	process_single_arg(char *arg, t_stack *stack_a)
{
	char	**numbers;
	int		i;
	int		num;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
		i++;
	while (--i >= 0)
	{
		if (!is_valid_number(numbers[i]) || !is_within_int_limits(numbers[i]))
		{
			free_split(numbers);
			return (0);
		}
		num = ft_atoi(numbers[i]);
		if (!push_to_stack(stack_a, num))
		{
			free_split(numbers);
			return (0);
		}
	}
	free_split(numbers);
	return (1);
}

static int	process_multiple_args(int ac, char **av, t_stack *stack_a)
{
	int	i;
	int	num;

	i = ac - 1;
	while (i > 0)
	{
		if (!is_valid_number(av[i]) || !is_within_int_limits(av[i]))
			return (0);
		num = ft_atoi(av[i]);
		if (!push_to_stack(stack_a, num))
			return (0);
		i--;
	}
	return (1);
}

int	process_args(int ac, char **av, t_stack *stack_a)
{
	if (ac == 2)
	{
		if (!process_single_arg(av[1], stack_a))
			return (0);
	}
	else
	{
		if (!process_multiple_args(ac, av, stack_a))
			return (0);
	}
	if (has_duplicates_in_stack(stack_a))
		return (0);
	return (1);
}