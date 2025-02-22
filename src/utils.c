/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:23:34 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 19:21:27 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Error input
void	error_input(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

//if only 3 values, hard coded swapping
void	argc_three(t_stack *stack)
{
	if (stack->a[0] == maxmin(stack->a, stack->a_size, 0))
	{
		reserve_rotate_a(stack);
		swap_a(stack);
		return ;
	}
	if (stack->a[0] == maxmin(stack->a, stack->a_size, 1))
	{
		if (stack->a[1] != maxmin(stack->a, stack->a_size, 0))
		{
			swap_a(stack);
			reserve_rotate_a(stack);
		}
		else
			rotate_a(stack);
		return ;
	}
	else
	{
		if (stack->a[1] == maxmin(stack->a, stack->a_size, 1))
			reserve_rotate_a(stack);
		else
			swap_a(stack);
	}
}

//check if the order of stack is correct from min to max
int	check_order(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->a_size)
	{
		if (stack->a[i - 1] > stack->a[i])
			return (1);
	}
	return (0);
}

//find min and max on array
//flag = 1 is for max value
//flag = 0 is for min value
int	maxmin(int *array, int array_size, int flag)
{
	int	i;
	int	temp;

	i = 0;
	temp = array[i];
	if (flag)
	{
		while (++i < array_size)
		{
			if (array[i] > temp)
				temp = array[i];
		}
	}
	else
	{
		while (++i < array_size)
		{
			if (array[i] < temp)
				temp = array[i];
		}
	}
	return (temp);
}
