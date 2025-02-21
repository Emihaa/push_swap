/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/21 17:05:29 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compare_order(t_stack *stack);

//Errir input
void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}


//calculate what value in A stack is cheapest to move to B stack
void calculate_cost(t_stack *stack)
{
    int cost;
    int i;
    int compare;
    int pos;

    i = 0;
    compare = 0;
    if (stack->a_size > 3)
    {
        while (i < stack->a_size)
        {
            cost = rot_cost(stack, i);
            cost++;
            if (compare == 0)
            {
                compare = cost;
                pos = i;
            }
            else
            {
                if (compare > cost)
                {
                    compare = cost;
                    pos = i;
                }
            }
            i++;
            cost = 0;
        }
        take_action(stack, pos);
    }
    compare_order(stack);
}

//compare if in a stack there is 3 or less left and start building it back together to A stack
//otherwise calculate_cost again
void compare_order(t_stack *stack)
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
void do_something(t_stack *stack)
{
    if (stack->a_size == 2 && check_order(stack))
    {
        swap_a(stack);
        return ;
    }
    else if (stack->a_size == 3 && check_order(stack))
        argc_three(stack);
    else if(stack->a_size > 3 && check_order(stack))
    {
        if (stack->b_size < 2)
        {
            push_to_b(stack);
            push_to_b(stack);
        }
        //if after pushing stuff to b, we are left with 3 on A stack. We want to check if it is left with 3 values,
        //dont calculate cost, but do argc_three and then start pushing values from B stack to A stack
        //so skip the calculate_cost action from A to B
        calculate_cost(stack);
    }
}


//initialize necessary stuff
void initialize_b(t_stack *stack)
{
    stack->b = malloc(stack->a_size * sizeof(int));
    if (!stack->b)
    {
        free(stack->b);
        free(stack->a);
        error_input();
    }
    stack->b_size = 0;
    stack->inverse_a = 0;
    stack->inverse_b = 0;
    stack->clockwise_a = 0;
    stack->clockwise_b = 0;
}

int main(int argc, char *argv[])
{
    static t_stack stack;
    
    stack.flag = 0;
    if (argc > 1)
    {
        if (argc == 2)
            split_array(argv, &stack);
        else
            atoi_array(argc, argv, &stack);
        initialize_b(&stack);
        do_something(&stack);
        free(stack.a);
        free(stack.b);
    }
    return (0);
}
