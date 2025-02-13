/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pushswap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:02 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/12 14:47:27 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push from b to a, the first element of stack
void push_to_a(t_stack *stack)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    if (stack->b_size != 0)
    {
        temp = stack->b[0];
        if (stack->b_size > 1)
        {
            while (++i < stack->b_size)
                stack->b[i - 1] = stack->b[i];
        }
        if (stack->a_size != 0)
        {
            i = stack->a_size;
            while (--i >= 0)
                stack->a[i + 1] = stack->a[i];
        }
        stack->a[0] = temp;
        stack->b_size--;
        stack->a_size++;
    }
    ft_putendl_fd("pa", 2);
}

//push from a to b, the first element of stack
void push_to_b(t_stack *stack)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    if (stack->a_size != 0)
    {
        temp = stack->a[0];
        if (stack->a_size > 1)
        {
            while (++i < stack->a_size)
                stack->a[i - 1] = stack->a[i];
        }
        if (stack->b_size != 0)
        {
            i = stack->b_size;
            while (--i >= 0)
                stack->b[i + 1] = stack->b[i];
        }
        stack->b[0] = temp;
        stack->a_size--;
        stack->b_size++;
    }
    ft_putendl_fd("pb", 2);
}

//swap both stacks same time
void swap_both(t_stack *stack)
{
    int temp;
    
    temp = 0;
    if (stack->b_size >= 2)
    {
        temp = stack->b[0];
        stack->b[0] = stack->b[1];
        stack->b[1] = temp;    
    }
    if (stack->a_size >= 2)
    {
        temp = stack->a[0];
        stack->a[0] = stack->a[1];
        stack->a[1] = temp;    
    }
    ft_putendl_fd("ss", 2);
}

// swap first 2 elements from stack b
void swap_b(t_stack *stack)
{
    int temp;
    
    temp = 0;
    if (stack->b_size >= 2)
    {
        temp = stack->b[0];
        stack->b[0] = stack->b[1];
        stack->b[1] = temp;    
    }
    ft_putendl_fd("sb", 2);
}
// swap first 2 elements from stack a
void swap_a(t_stack *stack)
{
    int temp;
    
    temp = 0;
    if (stack->a_size >= 2)
    {
        temp = stack->a[0];
        stack->a[0] = stack->a[1];
        stack->a[1] = temp;    
    }
    ft_putendl_fd("sa", 2);
}
