/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:23:34 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/20 17:54:04 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void argc_three(t_stack *stack)
{
    if (stack->a[0] == maxmin_a(stack, 0))
    {
        reserve_rotate_a(stack);
        swap_a(stack);
        return ;
    }
    if (stack->a[0] == maxmin_a(stack, 1))
    {
        if (stack->a[1] != maxmin_a(stack, 0))
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
        if (stack->a[1] == maxmin_a(stack, 1))
            reserve_rotate_a(stack);
        else
            swap_a(stack);
    }
}


//check if the order of stack is correct from min to max
int check_order(t_stack *stack)
{
    int i;

    i = 0;
    while (++i < stack->a_size)
    {
        if (stack->a[i - 1] > stack->a[i])
            return(1);
    }
    return (0);
}

//find min and max on B stack
//flag = 1 is for max value
//flag = 0 is for min value
int maxmin_b(t_stack *stack, int flag)
{
    int i;
    int temp;

    i = 0;
    temp = stack->b[i];
    if (flag)
    {
        while (++i < stack->b_size)
        {
            if (stack->b[i] > temp)
                temp = stack->b[i];
        }
    }
    else
    {
        while (++i < stack->b_size)
        {
            if (stack->b[i] < temp)
                temp = stack->b[i];
        }
    }
    return(temp);
}

//find min and max on A stack
//flag = 1 is for max value
//flag = 0 is for min value
int maxmin_a(t_stack *stack, int flag)
{
    int i;
    int temp;

    i = 0;
    temp = stack->a[i];
    if (flag)
    {
        while (++i < stack->a_size)
        {
            if (stack->a[i] > temp)
                temp = stack->a[i];
        }
    }
    else
    {
        while (++i < stack->a_size)
        {
            if (stack->a[i] < temp)
                temp = stack->a[i];
        }
    }
    return(temp);
}
