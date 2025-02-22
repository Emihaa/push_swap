/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:45:21 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 18:55:36 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do rotate_a && rotate_b same tme
void	rotate_both(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (stack->a_size >= 2)
	{
		temp = stack->a[0];
		while (++i < stack->a_size)
		{
			stack->a[i - 1] = stack->a[i];
		}
		stack->a[stack->a_size - 1] = temp;
	}
	i = 0;
	if (stack->b_size >= 2)
	{
		temp = stack->b[0];
		while (++i < stack->b_size)
		{
			stack->b[i - 1] = stack->b[i];
		}
		stack->b[stack->b_size - 1] = temp;
	}
	ft_putendl_fd("rr", 1);
}

//shift all the elements of the stack b one position upwards.
//the first element becomes the last
void	rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (stack->b_size >= 2)
	{
		temp = stack->b[0];
		while (++i < stack->b_size)
		{
			stack->b[i - 1] = stack->b[i];
		}
		stack->b[stack->b_size - 1] = temp;
	}
	ft_putendl_fd("rb", 1);
}

//shift all the elements of the stack a one position upwards.
//the first element becomes the last
void	rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (stack->a_size >= 2)
	{
		temp = stack->a[0];
		while (++i < stack->a_size)
		{
			stack->a[i - 1] = stack->a[i];
		}
		stack->a[stack->a_size - 1] = temp;
	}
	ft_putendl_fd("ra", 1);
}
