/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:02 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/11 20:16:57 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reserve roate both a && b
void reserve_rotate_both(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("rrr", 2);
}

//shift all elements of the stack down one position on
//stack b. The last element becomes the first.
void reserve_rotate_b(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("rrb", 2);
}


//shift all elements of the stack down one position on
//stack a. The last element becomes the first.
void reserve_rotate_a(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("rra", 2);
}

//do rotate_a && rotate_b same tme
void rotate_both(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("rr", 2);
}

//shift all the elements of the stack b one position upwards.
//the first element becomes the last
void rotate_b(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("rb", 2);
}

//shift all the elements of the stack a one position upwards.
//the first element becomes the last
void rotate_a(t_stack *stack)
{
    int temp;
    int i;

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
    ft_putendl_fd("ra", 2);
}


//push from b to a, the first element of stack
void push_to_a(t_stack *stack)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    if (stack->b_size != 0) //check if there is anything in b to push
    {
        temp = stack->b[0];
        if (stack->b_size > 1)
        {
            //move all rest one closer to top
            while (++i < stack->b_size) //need to recheck this ++i its 1 >= 3?
                stack->b[i - 1] = stack->b[i];
        }
        if (stack->a_size != 0)
        {
            i = stack->a_size;
            while (--i >= 0)
                stack->a[i + 1] = stack->a[i];
            //move all inside stack.a downwards to make space for temp
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
    if (stack->a_size != 0) //check if there is anything in b to push
    {
        temp = stack->a[0];
        if (stack->a_size > 1)
        {
            //move all rest one closer to top
            while (++i < stack->a_size) //need to recheck this ++i its 1 >= 3?
                stack->a[i - 1] = stack->a[i];
        }
        if (stack->b_size != 0)
        {
            i = stack->b_size;
            while (--i >= 0)
                stack->b[i + 1] = stack->b[i];
            //move all inside stack.a downwards to make space for temp
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
