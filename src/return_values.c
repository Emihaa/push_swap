/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:28:08 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/20 17:54:52 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//is given value "7" and finds the location of that value on B stack
static int find_value_pos_in_a(t_stack *stack, int value)
{
    int i;

    i = 0;
    while (stack->a[i] != value)
        i++;
    return (i);
}

//if value isnt new min/max finds the highest smaller value pos on B stack
static int find_target_in_a(t_stack *stack, int value)
{
    int i;
    int target;

    i = 0;
    target = 2147483647;
    while (i < stack->a_size)
    {
        if (stack->a[i] > value && stack->a[i] < target)
            target = stack->a[i];
        i++;
    }
    return (target); 
}

static void rotate_a_stack(t_stack *stack, int rot_a)
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
static void final_rot(t_stack *stack)
{
    int min;
    int target;
    int rot_a;
    
    min = maxmin_a(stack, 0);
    target = find_value_pos_in_a(stack, min);
    rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
    rotate_a_stack(stack, rot_a);   
}

//now we return everything from B stack to A
//We only return first value from B stack so we only need to rotate
//A stack when necessary to get the top value from B to correct spot
void return_values(t_stack *stack)
{
    int min;
    int max;
    int target;
    int rot_a;

    target = 0;
    while (stack->b_size != 0)
    {
        min = maxmin_a(stack, 0);
        max = maxmin_a(stack, 1);
        if (stack->b[0] < max && stack->b[0] > min)
        {
            target = find_value_pos_in_a(stack, find_target_in_a(stack, stack->b[0]));
            rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
            rotate_a_stack(stack, rot_a);
        }
        else
        {
            target = find_value_pos_in_a(stack, min);
            rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
            rotate_a_stack(stack, rot_a);
        }
        push_to_a(stack);
    }   
    final_rot(stack);  
}
