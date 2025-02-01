/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:24:38 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 13:34:42 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char	**numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

static int	check_empty_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_numbers(char **numbers)
{
	int	i;

	i = 1;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		if (!is_within_int_limits(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	process_args(int ac, char **av, t_stack *stack_a)
{
	char	**numbers;
	int		result;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (check_empty_arg(av[1]))
			return (0);
		numbers = ft_split(av[1], ' ');
		if (!numbers || !numbers[0])
		{
			free_split(numbers);
			return (0);
		}
		result = check_numbers(numbers);
		if (result)
			result = fill_stack(stack_a, numbers);
		free_split(numbers);
		return (result);
	}
	if (!check_numbers(av + 1))
		return (0);
	return (fill_stack(stack_a, av + 1));
}
