/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:15 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/06 22:03:21 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long nbr, int neg, int *flag)
{
	int	value;

	value = 0;
	if (neg == 1)
	{
		*flag = 1;
		value = 2147483647;
	}
	else
	{
		if (nbr != 2147483648)
			*flag = 1;
		value = -2147483648;
	}
	return (value);
}

int	ft_atoi(const char *nptr, int *flag)
{
	int		i;
	int		neg;
	unsigned int	value;

	i = 0;
	neg = 1;
	value = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + nptr[i] - '0';
		if (value > 2147483647)
			return (check_overflow(value, neg, flag));
		i++;
	}
	return ((int)(value * neg));
}
