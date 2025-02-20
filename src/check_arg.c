/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:43 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/20 22:12:19 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check for double digits in array
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

// //./push_swap "1 2 4 3" 76 90 "348 05" <- this isnt fixed, I want to give error
// //dont know how
// static void check_wrong_imput(char *str)
// {
//     int i;   
//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (ft_isdigit(str[i]))
// 		    i++;
//         else if (str[i] == '-' && ft_isdigit(str[i+1]))
//             i++;
//         else if (str[i] == '+' && ft_isdigit(str[i+1]))
//             i++;
//         else if (str[i] == ' ' && ft_isdigit(str[i+1]))
//             i++;
//         else if (str[i] == ' ' && str[i+1] == '-')
//             i++;
//         else if (str[i] == ' ' && str[i+1] == '+')
//             i++;
//         else
//         {
//             error_input();
//         }
//     }
// }

//./push_swap "1 2 4 3" 76 90 "348 05" <- this isnt fixed, I want to give error
//dont know how
static void check_wrong_imput(t_stack *stack, char **str, int flag)
{
    int i;
    int j;
    int y;
    
    i = 0;
    j = 0;
    y = 0;
    while (j < stack->a_size)
    {
        while (str[j][i] != '\0')
        {
            if ((ft_isdigit(str[j][i]) || (str[j][i] == '-' && ft_isdigit(str[j][i+1])) || (str[j][i] == '+' && ft_isdigit(str[j][i+1]))))
		        i++;
            else
            {
                if (flag)
                {
                    while (y < stack->a_size)
                    {
                        free(str[y]);
                        y++;
                    }
                    free(str);
                }
                free(stack->a);
                error_input();
            }
        }
        i = 0;
        j++;
    }
}

void atoi_array(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    stack->a = malloc((argc - 1) * sizeof(int));
    if (!stack)
        error_input();
    stack->a_size = argc - 1;
    check_wrong_imput(stack, argv, 0);
    while (++j < argc)
    {
        stack->a[i] = ft_atoi(argv[j], &stack->flag);
        if (!stack->a[i] || stack->flag == 1)
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
        if (!stack->a[i] || stack->flag == 1)
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


//check_wrong_imput laita toisin niin ett' tsiigaat temp check_wrong_imput
//ota checkist' pois space ni sit 43 80 74 31 "473 89 53 2478 49" ei toimi
void split_array(char **argv, t_stack *stack)
{
    int count;
    char **temp;
    
    count = 0;
    temp = ft_split(argv[1], ' ');
    if (!temp)
        error_input();
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
    check_wrong_imput(stack, &*temp, 1); //if this fails need to free everything
    array_loop(count, stack, temp);
    while (count-- > 0)
        free(temp[count]);
    free(temp);
    check_doubles(stack);
}
