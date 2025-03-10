/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 22:14:08 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate what value in A stack is cheapest to move to B stack
void	calculate_cost(t_stack *stack)
{
	int	cost;
	int	i;
	int	compare;
	int	pos;

	i = 0;
	compare = 0;
	while (i < stack->a_size)
	{
		cost = rot_cost(stack, i);
		cost++;
		if (compare == 0)
		{
			compare = cost;
			pos = i;
		}
		else if (compare > cost)
		{
			compare = cost;
			pos = i;
		}
		cost = 0;
		i++;
	}
	take_action(stack, pos);
}

//compare if in a stack there is 3 or less left and 
//start building it back together to A stack
//otherwise calculate_cost again
void	compare_order(t_stack *stack)
{
	if (stack->a_size <= 3)
	{
		if (check_order(stack))
			argc_three(stack);
		return_values(stack);
	}
	else
		calculate_cost(stack);
}

//The start: If there is 2 or 3 numbers
//hard suffle them manually, if more than 3 push 2 top values from A to B stack
//and then calculate_cost to move next value to B
static void	initial_check(t_stack *stack)
{
	if (stack->a_size == 2 && check_order(stack))
	{
		swap_a(stack);
		return ;
	}
	else if (stack->a_size == 3 && check_order(stack))
		argc_three(stack);
	else if (stack->a_size > 3 && check_order(stack))
	{
		if (stack->b_size < 2)
		{
			push_to_b(stack);
			push_to_b(stack);
		}
		if (stack->a_size > 3)
			calculate_cost(stack);
		else
			compare_order(stack);
	}
}

//initialize necessary stuff
static void	initialize_b(t_stack *stack)
{
	stack->b = malloc(stack->a_size * sizeof(int));
	if (!stack->b)
	{
		free(stack->a);
		error_input();
	}
	stack->b_size = 0;
	stack->inverse_a = 0;
	stack->inverse_b = 0;
	stack->clockwise_a = 0;
	stack->clockwise_b = 0;
	stack->counter = 0;
}

int	main(int argc, char *argv[])
{
	static t_stack	stack;

	stack.flag = 0;
	if (argc > 1)
	{
		if (argc == 2)
			split_array(argv, &stack);
		else
			atoi_array(argc, argv, &stack);
		initialize_b(&stack);
		initial_check(&stack);
		free(stack.a);
		free(stack.b);
	}
	return (0);
}
