/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:14:15 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 18:41:54 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate B stack based on gotten values.
//This is only when we need to rotate both stacks the same time, same direction
static void	common_rotations_b(t_stack *stack, int rot_a, int rot_b)
{
	while (rot_b != 0)
	{
		if (rot_b > rot_a && stack->inverse_b)
			rotate_b(stack);
		if (rot_b <= rot_a && stack->inverse_a && stack->inverse_b)
			rotate_both(stack);
		if (rot_b > rot_a && stack->clockwise_b)
			reserve_rotate_b(stack);
		if (rot_b <= rot_a && stack->clockwise_a && stack->clockwise_b)
			reserve_rotate_both(stack);
		rot_b--;
	}
}

//rotate A stack based on gotten values.
//This is only when we need to rotate both stacks the same time, same direction
static void	common_rotations_a(t_stack *stack, int rot_a, int rot_b)
{
	if (rot_a >= rot_b)
	{
		while (rot_a != 0)
		{
			if (rot_a > rot_b && stack->inverse_a)
				rotate_a(stack);
			if (rot_a <= rot_b && stack->inverse_a && stack->inverse_b)
				rotate_both(stack);
			if (rot_a > rot_b && stack->clockwise_a)
				reserve_rotate_a(stack);
			if (rot_a <= rot_b && stack->clockwise_a && stack->clockwise_b)
				reserve_rotate_both(stack);
			rot_a--;
		}
	}
	else if (rot_b > rot_a)
		common_rotations_b(stack, rot_a, rot_b);
}

//No double rotations so only invidual rotations
static void	no_common_rotations(t_stack *stack, int rot_a, int rot_b)
{
	while (rot_b != 0 && stack->clockwise_b)
	{
		reserve_rotate_b(stack);
		rot_b--;
	}
	while (rot_b != 0 && stack->inverse_b)
	{
		rotate_b(stack);
		rot_b--;
	}
	while (rot_a != 0 && stack->clockwise_a)
	{
		reserve_rotate_a(stack);
		rot_a--;
	}
	while (rot_a != 0 && stack->inverse_a)
	{
		rotate_a(stack);
		rot_a--;
	}
}

//pos gives the position of value to take action on
//calculate how many rots we have to do on A stack
//then to B stack
//check if we can do double rr
void	take_action(t_stack *stack, int pos)
{
	int	rot_a;
	int	rot_b;

	rot_a = count_a_stack_rot(stack, pos, &stack->inverse_a, \
							&stack->clockwise_a);
	rot_b = count_b_stack_rot(stack, pos, &stack->clockwise_b, \
							&stack->inverse_b);
	if ((stack->clockwise_a && stack->clockwise_b) || \
		(stack->inverse_a && stack->inverse_b))
		common_rotations_a(stack, rot_a, rot_b);
	else
		no_common_rotations(stack, rot_a, rot_b);
	stack->inverse_a = 0;
	stack->inverse_b = 0;
	stack->clockwise_a = 0;
	stack->clockwise_b = 0;
	push_to_b(stack);
	compare_order(stack);
}
