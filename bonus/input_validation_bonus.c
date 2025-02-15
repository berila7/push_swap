/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:55:12 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 13:31:12 by mberila          ###   ########.fr       */
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

int    is_valid_instruction(char *line)
{
    return (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0 ||
            ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0 ||
            ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "ra\n") == 0 ||
            ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0 ||
            ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0 ||
            ft_strcmp(line, "rrr\n") == 0);
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

int	has_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	if (!numbers || size <= 0)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
