/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:52:04 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/18 16:50:44 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//is given value "7" and finds the location of that value on B stack
int find_value_pos(t_stack *stack, int value)
{
    int i;

    i = 0;
    while (stack->b[i] != value)
        i++;
    return (i);
}

//if value isnt new min/max finds the highest smaller value pos on B stack
int find_target_value(t_stack *stack, int value)
{
    int i;
    int target;

    i = 0;
    target = -2147483647;
    while (i < stack->b_size)
    {
        if (stack->b[i] < value && stack->b[i] > target)
            target = stack->b[i];
        i++;
    }
    return (target); 
}

int count_a_stack_rot(t_stack *stack, int pos, int *inverse, int *clockwise)
{
    int cost;

    cost = 0;
    if (pos != 0)
    {
        if ((pos + 1) <= ((stack->a_size + 2 - 1)/2))
        {
            ft_printf("rot A stack inverse: %d\n", pos);
            *inverse = 1;
            cost += pos;
        }
        else
        {
            cost += stack->a_size - pos;
            *clockwise = 1;
            ft_printf("rot A stack clockwise: %d\n", cost);
        }
    }
    return (cost);
}

int count_b_stack_rot(t_stack *stack, int pos, int *clockwise, int *inverse)
{
    int min;
    int max;
    int cost;
    int value_pos;
    
    cost = 0;
    value_pos = 0;
    min = maxmin_b(stack, 0);
    max = maxmin_b(stack, 1);
    if (stack->a[pos] < max && stack->a[pos] > min) //value isnt new min or max
    {
        //find the index that above you want to add your value
        value_pos = find_value_pos(stack, find_target_value(stack, stack->a[pos]));
        ft_printf("find target value: %d\n", find_target_value(stack, stack->a[pos]));
        ft_printf("this is number that i want to be on top on B stack: %d\n", stack->b[value_pos]);
        //calculate how many rots that requires
        if ((value_pos + 1) <= ((stack->b_size + 2 - 1)/2))
        {
            ft_printf("rot B stack inverse: %d\n", value_pos);
            *inverse = 1;
            cost += value_pos;
        }
        else
        {
            cost += stack->b_size - value_pos;
            *clockwise = 1;
            ft_printf("rot B stack clockwise: %d\n", (stack->b_size - value_pos));
        }
    }
    else //value is new min/max
    {
        //find pos of max
        value_pos = find_value_pos(stack, max);
        ft_printf("this is number that i want to be on top on B stack: %d\n", stack->b[value_pos]);
        //calculate how many rots for that to top
        if ((value_pos + 1) <= ((stack->b_size + 2 - 1)/2))
        {
            ft_printf("rot B stack inverse: %d\n", value_pos);
            *inverse = 1;
            cost += value_pos;
        }
        else
        {
            cost += stack->b_size - value_pos;
            *clockwise = 1;
            ft_printf("rot B stack clockwise: %d\n", (stack->b_size - value_pos));
        }
    }
    return (cost);
}

// if case:
// 1   -7
// 6    5
// 8
// 9
//the code doest recognise that when rotating 6 or 9, we could do rr in both cases.
//because currently 5 is always rotated clockwise to top so it regocnices 9 & 5 rr clockwise
//but doesnt recognice 1 and 5 rr inverse
int rot_cost(t_stack *stack, int pos)
{
    int cost_a;
    int cost_b;
    int cost;
    int inverse;
    int clockwise;

    cost_a = 0;
    cost_b = 0;
    cost = 0;
    inverse = 0;
    clockwise = 0;
    ft_printf("\nvalue: %d\n", stack->a[pos]);
    //how much does it cost to rotate the value to top of A-stack
     //if value not already on top
    cost_a = count_a_stack_rot(stack, pos, &inverse, &clockwise);  
    //calculate how much it cost to rotate B-stack
       //is value already new min/max? If so then calculate how much we need
          //rotate B-stack to get max value to top
       //if value isnt new min/max, calculate the pos of smallest higher value on B-stack
       //and how much it takes to rotate it to top
    cost_b = count_b_stack_rot(stack, pos, &clockwise, &inverse);
    //then combine the double rr posibilities /but in this we need to know
    //which direction it is effective to rotate the stacks
    if (clockwise == 2 || inverse == 2)
    {
        if (cost_a >= cost_b)
            cost = cost_a;
        else if (cost_b > cost_a)
            cost = cost_b;
    }
    else
        cost = cost_a + cost_b;
    return(cost);
}
