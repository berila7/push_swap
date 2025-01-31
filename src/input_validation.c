/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:55:12 by mberila           #+#    #+#             */
/*   Updated: 2025/01/31 16:03:50 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
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
	num = ft_atoi(str);
	if (num > INT_MAX && num < INT_MIN)
		return (0);
	return (1);
}
