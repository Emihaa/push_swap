/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:28:08 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/19 22:07:05 by ehaanpaa         ###   ########.fr       */
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

static void final_rot(t_stack *stack)
{
    int i;
    int min;
    int target;
    int rot_a;
    
    min = maxmin_a(stack, 0);
    target = find_value_pos_in_a(stack, min);
    rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
    rotate_a_stack(stack, rot_a);
    
    //this just prints out stuff so i can see results     
    i = 0;
    ft_printf("------------------------------------\n");
   ft_printf("a stack: \n");
   while (i < stack->a_size)
   {
        ft_printf("%d\n", stack->a[i]);
        i++;
   }
    ft_printf("\n b stack: \n");
   i = 0;
    while (i < stack->b_size)
   {
        ft_printf("%d\n", stack->b[i]);
        i++;
   }
    ft_printf("------------------------------------\n");     
}

//now we return everything from B stack to A
//rotate A stack so that the top value on B goes to the correct spot
//then rotate A stack to get correct order
void return_values(t_stack *stack)
{
    int i;
    int min;
    int max;
    int target;
    int rot_a;

    target = 0;
    
    //this just prints out stuff so i can see results     
    i = 0;
    ft_printf("------------------------------------\n");
   ft_printf("a stack: \n");
   while (i < stack->a_size)
   {
        ft_printf("%d\n", stack->a[i]);
        i++;
   }
    ft_printf("\n b stack: \n");
   i = 0;
    while (i < stack->b_size)
   {
        ft_printf("%d\n", stack->b[i]);
        i++;
   }
    ft_printf("------------------------------------\n");
    
    ft_printf("\n--------- Start moving stuff back to A ----------\n");
    while (stack->b_size != 0)
    {
        min = maxmin_a(stack, 0);
        max = maxmin_a(stack, 1);
        //Since we always push the first value on B stack we dont need to figure out cost
        //we just need to find the correct position for B stack value inside A stack
        //rotate A stack when necessary and then push the value from B to A
        if (stack->b[0] < max && stack->b[0] > min) //if value isnt new min or max value
        {
            ft_printf("Move value %d to A stack\n", stack->b[0]);
            target = find_value_pos_in_a(stack, find_target_in_a(stack, stack->b[0]));
            rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
            ft_printf("put on top of this A value: %d\n\n", stack->a[target]);
            rotate_a_stack(stack, rot_a);
        }
        else //value is new min or max value
        {
            ft_printf("Move new min/max value %d to A stack\n", stack->b[0]);
            target = find_value_pos_in_a(stack, min);
            rot_a = count_a_stack_rot(stack, target, &stack->inverse_a, &stack->clockwise_a);
            ft_printf("put on top of this A value: %d\n\n", stack->a[target]);
            rotate_a_stack(stack, rot_a);
        }
        push_to_a(stack);
           //this just prints out stuff so i can see results     
    
    
    i = 0;
    ft_printf("------------------------------------\n");
    ft_printf("a stack: \n");
    while (i < stack->a_size)
    {
        ft_printf("%d\n", stack->a[i]);
        i++;
        }
        ft_printf("\n b stack: \n");
        i = 0;
        while (i < stack->b_size)
        {
        ft_printf("%d\n", stack->b[i]);
        i++;
        }
    ft_printf("------------------------------------\n");
    }
    final_rot(stack);  
}