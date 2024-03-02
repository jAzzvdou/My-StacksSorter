#include "push_swap.h"

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

int	verify_cost(t_pushswap *ps, int cheapest, int cost)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < ps->r->size)
	{
		tmp = cost_to_top(ps->a, ps->r->index_arr[i]);
		if (tmp < 0)
		{
			if (-tmp < cheapest)
			{
				cheapest = -tmp;
				cost = tmp;
			}
		}
		else if (tmp < cheapest)
		{
			cheapest = tmp;
			cost = tmp;
		}
	}
	return (cost);
}

int	cheapest_in_range(t_pushswap *ps)
{
	int	cost;
	int	cheapest;

	cost = 0;
	cheapest = 2147483647;
	return (verify_cost(ps, cheapest, cost));
}
