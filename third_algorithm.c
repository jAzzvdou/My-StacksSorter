#include "push_swap.h"

#include <stdio.h>

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

void    set_index(t_stack *stack, int *array, int size)
{
        int     i;
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

int	cheapest_in_range(t_pushswap *ps, int range)
{
	int	i;
	int	tmp;
	int	cost;
	int	smallest;

	smallest = 2147483647;
	cost = 0;
	i = -1;
        while (++i < range)
        {
                tmp = cost_to_top(ps->a, i);
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
	return (cost);
}

int	cheapest_in_range2(t_pushswap *ps, int range)
{
	int	i;
	int	tmp;
	int	cost;
	int	smallest;

	smallest = 2147483647;
	cost = 0;
	i = -1;
	while (++i < range)
	{
		tmp = cost_to_top(ps->b, stack_size(ps->b) - i - 1);
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
	return (cost);
}

void	make_moves(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rra(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			ra(ps);
	}
	pb(ps);
}

void	make_moves2(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rrb(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			rb(ps);
	}
	pa(ps);
}

void	third_algorithm(t_pushswap *ps)
{
	int	size;
	int	cost;
	int	*array;
	int	range;

	range = 10;
	while (ps->a)
	{
		size = stack_size(ps->a);
		array = bubblesort(stack_to_array(ps->a), size);
		set_index(ps->a, array, size);
		cost = cheapest_in_range(ps, range);
		make_moves(ps, cost);
		range--;
		if (!range)
			range = 10;
	}
	range = 1;
	while (ps->b)
	{
		size = stack_size(ps->b);
		array = bubblesort(stack_to_array(ps->b), size);
		set_index(ps->b, array, size);
		cost = cheapest_in_range2(ps, range);
		make_moves2(ps, cost);
	}
}
