/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/13 20:39:05 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

int rot_cost(t_stack *stack, int pos)
{
    int cost;
    int min;
    int max;

    cost = 0;
    min = maxmin_b(stack, 0);
    max = maxmin_b(stack, 1);
    ft_printf("%d\n", pos);
    //how much does it cost to rotate the value to top of A-stack
     //if value not already on top
    
    //calculate how much it cost to rotate B-stack
       //is value already new min/max? If so then calculate how much we need
          //rotate B-stack to get max value to top
       //if value isnt new min/max, calculate the pos of smallest higher value on B-stack
       //and how much it takes to rotate it to top
    
    //then combine the double rr posibilities /but in this we need to know
       //which direction it is effective to rotate the stacks
    return(cost);
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
        ft_printf("\nvalue: %d\n", stack->a[i]);
        rot_cost(stack, i);
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
    ft_printf("results: move pos %d\n", pos);
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
        //do stuff to get correct order
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
