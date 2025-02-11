/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:49 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/11 20:28:37 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_stack
{
    int *b;
    int *a;
    int top;
    int a_size;
    int b_size;
    int flag;
} t_stack;

//push_swap.c
void error_input();

//check_arg.c
void atoi_array(int argc, char **argv, t_stack *stack);
void split_array(char **argv, t_stack *stack);

//operation_utils.c
void reserve_rotate_both(t_stack *stack);
void reserve_rotate_b(t_stack *stack);
void reserve_rotate_a(t_stack *stack);
void rotate_both(t_stack *stack);
void rotate_b(t_stack *stack);
void rotate_a(t_stack *stack);
void push_to_a(t_stack *stack);
void push_to_b(t_stack *stack);
void swap_both(t_stack *stack);
void swap_b(t_stack *stack);
void swap_a(t_stack *stack);

//utils.c
void argc_three(t_stack *stack);
int check_order(t_stack *stack);
int maxmin_b(t_stack *stack, int flag);
int maxmin_a(t_stack *stack, int flag);


#endif