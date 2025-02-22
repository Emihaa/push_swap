/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:28:08 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 19:20:18 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//final a stack rotation based on if which is cheaper
static void	rotate_a_stack(t_stack *stack, int rot_a)
{
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
	stack->inverse_a = 0;
	stack->clockwise_a = 0;
}

//All values are on A stack, do a final rotation to get minimum value to top
static void	final_rot(t_stack *stack)
{
	int	min;
	int	target;
	int	rot_a;

	min = maxmin(stack->a, stack->a_size, 0);
	target = find_value_pos(stack->a, min);
	rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, \
							&stack->clockwise_a);
	rotate_a_stack(stack, rot_a);
}

//now we return everything from B stack to A
//We only return first value from B stack so we only need to rotate
//A stack when necessary to get the top value from B to correct spot
void	return_values(t_stack *stack)
{
	int	min;
	int	max;
	int	rot_a;

	while (stack->b_size != 0)
	{
		min = maxmin(stack->a, stack->a_size, 0);
		max = maxmin(stack->a, stack->a_size, 1);
		if (stack->b[0] < max && stack->b[0] > min)
		{
			rot_a = count_a_stack_rot(stack, find_value_pos(stack->a, \
									find_target_in_a(stack, stack->b[0])), \
									&stack->inverse_a, &stack->clockwise_a);
			rotate_a_stack(stack, rot_a);
		}
		else
		{
			rot_a = count_a_stack_rot(stack, find_value_pos(stack->a, min), \
									&stack->inverse_a, &stack->clockwise_a);
			rotate_a_stack(stack, rot_a);
		}
		push_to_a(stack);
	}
	final_rot(stack);
}
