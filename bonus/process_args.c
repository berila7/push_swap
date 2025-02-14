/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:24:38 by mberila           #+#    #+#             */
/*   Updated: 2025/02/03 11:17:55 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_numbers(char **numbers)
{
	int	i;

	i = 0;
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

static char	*join_args(int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_strdup("");
	i = 1;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		if (i < ac - 1)
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			free(tmp);
		}
		i++;
	}
	return (str);
}

int	process_args(int ac, char **av, t_stack *stack_a)
{
	char	**numbers;
	int		result;
	char	*str;

	if (ac < 2)
		return (0);
	str = join_args (ac, av);
	if (!str)
		return (0);
	numbers = ft_split(str, ' ');
	free(str);
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
