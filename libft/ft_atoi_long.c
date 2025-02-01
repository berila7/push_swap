/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:20:19 by mberila           #+#    #+#             */
/*   Updated: 2025/02/01 11:15:34 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_spaces_and_sign(const char *str, int *i, int *sign)
{
	*sign = 1;
	if (!str)
		return (0);
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32))
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	return (1);
}

long	ft_atoi_long(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	if (!handle_spaces_and_sign(str, &i, &sign))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		i++;
	}
	return (result * sign);
}
