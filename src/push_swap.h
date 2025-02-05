/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:49 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/05 23:49:52 by ehaanpaa         ###   ########.fr       */
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
    int size;
} t_stack;

//push_swap.c
void error_input();

//check_arg.c
void check_doubles(t_stack *stack);
void check_wrong_imput(char *str);
int check_int_maxmin(char *argv, int nbr);
void atoi_array(int argc, char **argv, t_stack *stack);
void split_array(char **argv, t_stack *stack);


#endif