/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:22:45 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 19:18:47 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//is given value "7" and finds the location of that value on B stack
int	find_value_pos(int *array, int value)
{
	int	i;

	i = 0;
	while (array[i] != value)
		i++;
	return (i);
}

//if value isnt new min/max finds the highest smaller value pos on B stack
int	find_target_in_b(t_stack *stack, int value)
{
	int	i;
	int	target;

	i = 0;
	target = -2147483648;
	while (i < stack->b_size)
	{
		if (stack->b[i] < value && stack->b[i] > target)
			target = stack->b[i];
		i++;
	}
	return (target);
}

//if value isnt new min/max finds the highest smaller value pos on B stack
int	find_target_in_a(t_stack *stack, int value)
{
	int	i;
	int	target;

	i = 0;
	target = 2147483647;
	while (i < stack->a_size)
	{
		if (stack->a[i] > value && stack->a[i] < target)
			target = stack->a[i];
		i++;
	}
	return (target);
}
