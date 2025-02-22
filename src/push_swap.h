/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:14:49 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 19:07:30 by ehaanpaa         ###   ########.fr       */
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
	int	*b;
	int	*a;
	int	top;
	int	a_size;
	int	b_size;
	int	inverse_a;
	int	clockwise_a;
	int	inverse_b;
	int	clockwise_b;
	int	flag;
	int	counter;
}	t_stack;

//calculate_cost.c
int		count_a_stack_rot(t_stack *stack, int pos, \
						int *inverse, int *clockwise);
int		count_b_stack_rot(t_stack *stack, int pos, \
						int *clockwise, int *inverse);
int		rot_cost(t_stack *stack, int pos);

//check_arg.c
void	atoi_array(int argc, char **argv, t_stack *stack);
void	split_array(char **argv, t_stack *stack);

//find_target.c
int		find_value_pos(int *array, int value);
int		find_target_in_b(t_stack *stack, int value);
int		find_target_in_a(t_stack *stack, int value);

//operation_pushswap.c
void	push_to_a(t_stack *stack);
void	push_to_b(t_stack *stack);
void	swap_both(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_a(t_stack *stack);

//operation_reserve.c
void	reserve_rotate_both(t_stack *stack);
void	reserve_rotate_b(t_stack *stack);
void	reserve_rotate_a(t_stack *stack);

//operation_rotation.c
void	rotate_both(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_a(t_stack *stack);

//push_swap.c
void	calculate_cost(t_stack *stack);
void	compare_order(t_stack *stack);

//return_values.c
void	return_values(t_stack *stack);

//take_action.c
void	take_action(t_stack *stack, int pos);

//utils.c
void	error_input(void);
void	argc_three(t_stack *stack);
int		check_order(t_stack *stack);
int		maxmin(int *array, int array_size, int flag);

#endif
