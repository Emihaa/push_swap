/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:43 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/21 17:16:12 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_doubles(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < stack->a_size)
    {
        while (++j <= stack->a_size - 1)
        {
            if (stack->a[i] == stack->a[j])
            {
                free(stack->a);
                error_input();
            }
        }
        i++;
        j = i;
    }
}

//./push_swap "1 2 4 3" 76 90 "348 05" <- this isnt fixed, I want to give error
//dont know how
//fix this 11-1 2 -3
static void check_wrong_imput(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]))
		    i++;
        else if (str[i] == '-' && ft_isdigit(str[i+1]))
            i++;
        else if (str[i] == '+' && ft_isdigit(str[i+1]))
            i++;
        else if (str[i] == ' ' && ft_isdigit(str[i+1]))
            i++;
        else if (str[i] == ' ' && str[i+1] == '-')
            i++;
        else if (str[i] == ' ' && str[i+1] == '+')
            i++;
        else
        {
            error_input();
        }
    }
}

void atoi_array(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;
    char *flag;
    
    i = 0;
    j = 0;
    while (++j < argc)
    {
        check_wrong_imput(argv[j]);
        flag = ft_strchr(argv[j], ' ');
        if (flag)
        {
            error_input();
        }
    }
    j = 0;
    stack->a = malloc((argc - 1) * sizeof(int));
    if (!stack)
    {
        error_input();
    }
    stack->a_size = argc - 1;
    while (++j < argc)
    {
        stack->a[i] = ft_atoi(argv[j], &stack->flag);
        if (stack->flag == 1)
        {
            free(stack->a);
            error_input();
        }
        i++;
    }
    check_doubles(stack);
}

static void array_loop(int count, t_stack *stack, char **temp)
{
    int i;
    
    i = 0;
    while (i < count)
    {
        stack->a[i] = ft_atoi(temp[i], &stack->flag);
        if (stack->flag == 1)
        {
            free(stack->a);
            while (count-- > 0)
                free(temp[count]);
            free(temp);
            error_input();
        }
        i++;
    }
}

void split_array(char **argv, t_stack *stack)
{
    int count;
    char **temp;
    
    count = 0;
    check_wrong_imput(argv[1]);
    temp = ft_split(argv[1], ' ');
    if (!temp)
    {
        error_input();
    }
    while (temp[count])
        count++;
    stack->a = malloc(count * sizeof(int));
    if (!stack->a)
    {
        while (count-- > 0)
            free(temp[count]);
        free(temp);
        error_input();
    }
    stack->a_size = count;
    array_loop(count, stack, temp);
    while (count-- > 0)
        free(temp[count]);
    free(temp);
    check_doubles(stack);
}