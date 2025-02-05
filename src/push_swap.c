/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:52 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/05 23:46:21 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_input()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    static t_stack stack;
    
    if (argc > 1)
    {
        if (argc == 2)
            split_array(argv, &stack);
        else
            atoi_array(argc, argv, &stack);
    }
    check_doubles(&stack);
    free(stack.a);
    return (0);
}
