/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:55:07 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 18:57:01 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reserve rotate both a && b
void	reserve_rotate_both(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = stack->a_size;
	if (stack->a_size >= 2)
	{
		temp = stack->a[stack->a_size - 1];
		while (--i > 0)
		{
			stack->a[i] = stack->a[i - 1];
		}
		stack->a[0] = temp;
	}
	i = stack->b_size;
	if (stack->b_size >= 2)
	{
		temp = stack->b[stack->b_size - 1];
		while (--i > 0)
		{
			stack->b[i] = stack->b[i - 1];
		}
		stack->b[0] = temp;
	}
	ft_putendl_fd("rrr", 1);
}

//shift all elements of the stack down one position on
//stack b. The last element becomes the first.
void	reserve_rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = stack->b_size;
	if (stack->b_size >= 2)
	{
		temp = stack->b[stack->b_size - 1];
		while (--i > 0)
		{
			stack->b[i] = stack->b[i - 1];
		}
		stack->b[0] = temp;
	}
	ft_putendl_fd("rrb", 1);
}

//shift all elements of the stack down one position on
//stack a. The last element becomes the first.
void	reserve_rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = stack->a_size;
	if (stack->a_size >= 2)
	{
		temp = stack->a[stack->a_size - 1];
		while (--i > 0)
		{
			stack->a[i] = stack->a[i - 1];
		}
		stack->a[0] = temp;
	}
	ft_putendl_fd("rra", 1);
}
