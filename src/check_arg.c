/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaanpaa <ehaanpaa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:43 by ehaanpaa          #+#    #+#             */
/*   Updated: 2025/02/22 22:16:24 by ehaanpaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_doubles(t_stack *stack)
{
	int	i;
	int	j;

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

static void	check_wrong_imput(char *str)
{
	int	i;

	i = 0;
    if (str[i] == '\0')
        error_input();
    else
    {
	    while (str[i] != '\0')
	    {
		    if (ft_isdigit(str[i]))
			    i++;
		    else if (i != 0 && str[i] == '+' && ft_isdigit(str[i + 1]) && \
				    str[i - 1] != ' ')
			    error_input();
		    else if (i != 0 && str[i] == '-' && ft_isdigit(str[i + 1]) && \
				    str[i - 1] != ' ')
			    error_input();
		    else if ((str[i] == '-' && ft_isdigit(str[i + 1])) || \
            (str[i] == '+' && ft_isdigit(str[i + 1])) || \
            (str[i] == ' ' && ft_isdigit(str[i + 1])))
			    i++;
		    else if ((str[i] == ' ' && str[i + 1] == '-') || \
				    (str[i] == ' ' && str[i + 1] == '+'))
			    i++;
		    else
		    	error_input();
	    }
    }
}

void	atoi_array(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		check_wrong_imput(argv[i]);
		if (ft_strchr(argv[i], ' '))
			error_input();
	}
	i = 0;
	stack->a = malloc((argc - 1) * sizeof(int));
	if (!stack)
		error_input();
	stack->a_size = argc - 1;
	while (++i < argc)
	{
		stack->a[i - 1] = ft_atoi(argv[i], &stack->flag);
		if (stack->flag == 1)
		{
			free(stack->a);
			error_input();
		}
	}
	check_doubles(stack);
}

static void	array_loop(int count, t_stack *stack, char **temp)
{
	int	i;

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

void	split_array(char **argv, t_stack *stack)
{
	char	**temp;

	check_wrong_imput(argv[1]);
	temp = ft_split(argv[1], ' ');
	if (!temp)
		error_input();
	while (temp[stack->counter])
		stack->counter++;
	stack->a = malloc(stack->counter * sizeof(int));
	if (!stack->a)
	{
		while (stack->counter-- > 0)
			free(temp[stack->counter]);
		free(temp);
		error_input();
	}
	stack->a_size = stack->counter;
	array_loop(stack->counter, stack, temp);
	while (stack->counter-- > 0)
		free(temp[stack->counter]);
	free(temp);
	check_doubles(stack);
}
