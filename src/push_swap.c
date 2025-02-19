/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/19 17:32:20 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compare_order(t_stack *stack);

void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}


//if the cost is 1 just do that without calculating the rest
void calculate_cost(t_stack *stack)
{
    int cost;
    int i;
    int compare;
    int pos;

    i = 0;
    compare = 0;
    while (i < stack->a_size)//if there are like 100 values, it doesnt make sense to go through all
    {//at what point do i stop going down the list?
        cost = rot_cost(stack, i);
        cost++; //plus cost++ for push_to b stack
        //then compare with the previous cost which one cost less and remember that
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
        ft_printf("cost: %d\n", cost);
        cost = 0;
    }
    ft_printf("\n-----results: move value %d -----\n", stack->a[pos]);
    take_action(stack, pos);
    compare_order(stack);
}

//if i at start push 2 and in stack A there is less than 3 this segment faults
void compare_order(t_stack *stack)
{
       //this just prints out stuff so i can see results     
   int i = 0;
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

////////////////////////////////////////////////////
 
    if (stack->a_size <= 3)
    {
        ft_printf("-- only 3 left --\n");
        if (check_order(stack))
            argc_three(stack);
        return_values(stack);
    }
    else
        calculate_cost(stack);
}

void do_something(t_stack *stack)
{
       //this just prints out stuff so i can see results     
   int i = 0;
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

 
    if (stack->a_size == 2 && check_order(stack))
    {
        swap_a(stack);
        return ;
    }
    else if (stack->a_size == 3 && check_order(stack))
        argc_three(stack);
    else if(stack->a_size > 3 && check_order(stack))
    { //this maybe has to be recursive till we get else
        if (stack->b_size < 2)
        {
            push_to_b(stack);
            push_to_b(stack);
        }
        calculate_cost(stack);
        //compare if correct order, if not calculate more cost
        //if A stack has only 3 left, do argc_three
        //and then start pushing stuff from B stack to A stack
    }

    
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
