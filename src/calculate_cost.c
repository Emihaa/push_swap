/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:52:04 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 19:22:19 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count A stack rotation amount based on the given position
int	count_a_stack_rot(t_stack *stack, int pos, int *inverse, int *clockwise)
{
	int	cost;

	cost = 0;
	if (pos != 0)
	{
		if ((pos + 1) <= ((stack->a_size + 2 - 1) / 2))
		{
			*inverse = 1;
			cost += pos;
		}
		else
		{
			cost += stack->a_size - pos;
			*clockwise = 1;
		}
	}
	return (cost);
}

//value cost to move if value isnt new min/max
static int	value_cost(t_stack *stack, int pos, int *clockwise, int *inverse)
{
	int	cost;
	int	value_pos;

	cost = 0;
	value_pos = 0;
	value_pos = find_value_pos(stack->b, \
									find_target_in_b(stack, stack->a[pos]));
	if ((value_pos + 1) <= ((stack->b_size + 2 - 1) / 2))
	{
		*inverse = 1;
		cost += value_pos;
	}
	else
	{
		cost += stack->b_size - value_pos;
		*clockwise = 1;
	}
	return (cost);
}

//value cost to move if calue is new min/max value
static int	minmax_cost(t_stack *stack, int max, int *clockwise, int *inverse)
{
	int	value_pos;
	int	cost;

	value_pos = 0;
	cost = 0;
	value_pos = find_value_pos(stack->b, max);
	if ((value_pos + 1) <= ((stack->b_size + 2 - 1) / 2))
	{
		*inverse = 1;
		cost += value_pos;
	}
	else
	{
		cost += stack->b_size - value_pos;
		*clockwise = 1;
	}
	return (cost);
}

//count B stack rotation amount based on the given position
//more complex and probably cannot be combined with another one
//checks if value is the new min or max
//or needs to go between
int	count_b_stack_rot(t_stack *stack, int pos, int *clockwise, int *inverse)
{
	int	min;
	int	max;
	int	cost;

	cost = 0;
	min = maxmin(stack->b, stack->b_size, 0);
	max = maxmin(stack->b, stack->b_size, 1);
	if (stack->a[pos] < max && stack->a[pos] > min)
		cost = value_cost(stack, pos, clockwise, inverse);
	else
		cost = minmax_cost(stack, max, clockwise, inverse);
	return (cost);
}

//get cost for both A and B stack cost
//calculation and also check the common rotations
int	rot_cost(t_stack *stack, int pos)
{
	int	cost_a;
	int	cost_b;
	int	cost;
	int	inverse;
	int	clockwise;

	cost_a = 0;
	cost_b = 0;
	cost = 0;
	inverse = 0;
	clockwise = 0;
	cost_a = count_a_stack_rot(stack, pos, &inverse, &clockwise);
	cost_b = count_b_stack_rot(stack, pos, &clockwise, &inverse);
	if (clockwise == 2 || inverse == 2)
	{
		if (cost_a >= cost_b)
			cost = cost_a;
		else if (cost_b > cost_a)
			cost = cost_b;
	}
	else
		cost = cost_a + cost_b;
	return (cost);
}
