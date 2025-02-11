/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/11 20:24:52 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

void calculate_cost(t_stack *stack)
{
    int min;
    int max;
    int i;
    int cost;

    min = maxmin_b(stack, 0);
    max = maxmin_b(stack, 1);
    ft_printf("min & max: %d %d\n", min, max);
    i = 0;
    cost = 0;
    while (i < stack->a_size)
    {
        if (stack->a[i] < max && stack->a[i] > min) //if the value is not more than max or smaller than min
        {
            cost++; //i need to count here how many times i need to rotate the stack b
            //to get the number in as the max value
        }
        i++;
    }
}

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
    { //this maybe has to be recursive till we get else
        if (stack->b_size < 2)
        {
            push_to_b(stack);
            push_to_b(stack);
        }
        calculate_cost(stack);
        ft_printf("incorrect order\n"); //do stuff to get correct order
    }
    else
    {
        write(1, "\n", 1);
        return ;
    }

    
   //this just prints out stuff so i can see results     
   int i = 0;
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
   ft_printf("stack.a_size: %d\n", stack->a_size);
   ft_printf("stack.b_size: %d\n", stack->b_size);
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
