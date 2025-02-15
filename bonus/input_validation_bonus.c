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
    if (!line)
        return (0);
    return (ft_strncmp(line, "sa\n", 3) == 0 || ft_strncmp(line, "sb\n", 3) == 0 ||
            ft_strncmp(line, "ss\n", 3) == 0 || ft_strncmp(line, "pa\n", 3) == 0 ||
            ft_strncmp(line, "pb\n", 3) == 0 || ft_strncmp(line, "ra\n", 3) == 0 ||
            ft_strncmp(line, "rb\n", 3) == 0 || ft_strncmp(line, "rr\n", 3) == 0 ||
            ft_strncmp(line, "rra\n", 4) == 0 || ft_strncmp(line, "rrb\n", 4) == 0 ||
            ft_strncmp(line, "rrr\n", 4) == 0);
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
