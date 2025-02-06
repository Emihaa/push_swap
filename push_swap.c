/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/06 23:12:00 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

// void push_a(t_stack *stack)
// {
    
// }

// void ss(t_stack *stack)
// {
//     swap_a(stack);
//     swap_b(stack);
// }

//what is on the top? zero or the last added int of the stack?
//do i need to keep update the size of stack all the time? I have the max size
//but the max size changes right? If the stack size change do i malloc it completely again or null
//the empty integers? Do i keep info all the time what is at the top of each stack
//but what is the point if i need to check inside every "plate" anyway?


// void swap_b(t_stack *stack)
// {
//     int temp;
    
//     if (stack->size == 2) //this is incorrect but for reference
//     {
//         temp = stack->b[0]; //is the top zero?
//         stack->b[0] = stack->b[1];
//         stack->b[1] = temp;    
//     }
// }

// void swap_a(t_stack *stack)
// {
//     int temp;
    
//     if (stack->size == 2) //this is incorrect but for reference
//     {
//         temp = stack->a[0]; //is the top zero?
//         stack->a[0] = stack->a[1];
//         stack->a[1] = temp;    
//     }
// }



void initialize_b(t_stack *stack)
{
    stack->b = malloc(stack->size * sizeof(int));
    if (!stack->b)
    {
        free(stack->b);
        free(stack->a);
        error_input();
    }
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
        free(stack.a);
        free(stack.b);
    }
    return (0);
}
