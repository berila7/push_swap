/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:24:38 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 19:44:22 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char	**numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static int	check_numbers(char	**numbers)
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

int	process_args(int ac, char **av)
{
	char	**numbers;
	int		result;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			return (0);
		result = check_numbers(numbers);
		free_split(numbers);
		return (result);
	}
	return (check_numbers(av + 1));
}
