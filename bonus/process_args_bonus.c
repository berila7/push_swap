/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:24:38 by mberila           #+#    #+#             */
/*   Updated: 2025/02/16 16:39:50 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	check_numbers(char **numbers, int **temp_array, int *count)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i])
			|| !is_within_int_limits(numbers[i]))
			return (0);
		i++;
	}
	if (!convert_to_array(numbers, temp_array, count))
		return (0);
	if (has_duplicates(*temp_array, *count))
	{
		free(*temp_array);
		*temp_array = NULL;
		return (0);
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
	int		*temp_array;
	int		count;

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
	count = 0;
	result = check_numbers(numbers, &temp_array, &count);
	if (result)
		result = fill_stack(stack_a, temp_array, count);
	free_split(numbers);
	return (result);
}
