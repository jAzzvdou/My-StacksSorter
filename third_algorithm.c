/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:02 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/09 17:27:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int	i;
	int	*array;
	int	size;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	*bubblesort(int *stack, int size)
{
        int     i;
        int     ii;
        int     tmp;

        i = -1;
        while (++i < size)
        {
                ii = i;
                while (++ii < size)
                {
                        if (stack[i] > stack[ii])
                        {
                                tmp = stack[i];
                                stack[i] = stack[ii];
                                stack[ii] = tmp;
                        }
                }
        }
	return (stack);
}

int	cost_to_top(t_stack *stack, int index)
{
	int	i;
	int	size;
	
	size = stack_size(stack);
	i = 0;
	while (stack)
	{
		if (stack->index == index)
		{
			if (i < size / 2)
				return (i);
			else
				return (-(size - i));
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

void	set_index(t_stack *stack, int *array, int size)
{
	int	i;

	while (stack)
	{
		i = -1;
		while (++i < size)
		{
			if (stack->value == array[i])
				stack->index = i;
		}
		stack = stack->next;
	}
}

#include <stdio.h>
void	third_algorithm(t_pushswap *ps, int range)
{
	int	size = stack_size(ps->a);
	int	*array = bubblesort(stack_to_array(ps->a), size);

	set_index(ps->a, array, size);
	int i = -1;
	int smallest = 2147483647;
	int cost = 0;
	while (ps->a)
	{
		while (++i <= range && range < size)
		{
			int tmp = cost_to_top(ps->a, i);
			if (tmp < 0)
			{
				if (-tmp < smallest)
				{
					smallest = -tmp;
					cost = tmp;
				}
			}
			else if (tmp < smallest)
			{
				smallest = tmp;
				cost = tmp;
			}
		}
		if (cost < 0)
		{
			while (cost++)
				rra(ps);
		}
		else
		{
			while (cost--)
				ra(ps);
		}
		pb(ps);
		range += range;
	}
	printf("smallest: %d\n", cost);
}
