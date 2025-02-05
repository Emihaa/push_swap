/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:43 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/05 23:46:26 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check double int values
void check_doubles(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (stack->a[stack->size])
        stack->size++;
    stack->size--;
    while (stack->a[i] < stack->size)
    {
        while (++j <= stack->size)
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

//./push_swap "1 2 4 3" 76 90 "348 05 <- this isnt fixed
void check_wrong_imput(char *str)
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
            exit(EXIT_FAILURE);
        }
    }
}
int check_int_maxmin(char *argv, int nbr)
{
    char *value;
    int i;
    int j;
    
    i = 0;
    j = 0;
    value = ft_itoa(nbr);
    if (argv[i] == '+')
        i++;
    while (argv[i])
    {
        if (argv[i] != value[j])
        {
            free(value);
            return(1);
        }
        i++;
        j++;
    }
    free(value);
    return(0);
}

void atoi_array(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (++j < argc)
        check_wrong_imput(argv[j]);
    j = 0;
    stack->a = malloc((argc - 1) * sizeof(int));
    if (!stack)
        exit(EXIT_FAILURE);
    while (++j < argc)
    {
        stack->a[i] = atoi(argv[j]);
        if (!stack->a[i])
        {
            free(stack->a);
            error_input();
        }
        if (check_int_maxmin(argv[j], stack->a[i]))
        {
            free(stack->a);
            error_input();
        }
        ft_printf("%d\n", stack->a[i]);
        i++;
    }
}

void split_array(char **argv, t_stack *stack)
{
    int i = 0;
    int count = 0;
    char **temp;
    
    check_wrong_imput(argv[1]);
    temp = ft_split(argv[1], ' ');
    if (!temp)
        exit(EXIT_FAILURE);
    while (temp[count])
        count++;
    stack->a = malloc(count * sizeof(int));
    if (!stack->a)
    {
        while (count-- > 0)
            free(temp[count]);
        free(temp);
        exit(EXIT_FAILURE);
    }
    while (i < count)
    {
        stack->a[i] = atoi(temp[i]);
        if (!stack->a[i])
        {
            free(stack->a);
            while (count-- > 0)
                free(temp[count]);
            free(temp);
            error_input();
        }
        ft_printf("%d\n", stack->a[i]);
        i++;
    }
    while (count-- > 0)
        free(temp[count]);
    free(temp);
}
