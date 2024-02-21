#include "push_swap.h"

#include <stdio.h>

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

void	third_algorithm(t_pushswap *ps)
{
	int	size;
	int	range;
	int	start;
	int	end;

	size = stack_size(ps->a);
	range = set_range(size);
	start = ((size / 2) + (size % 2)) - range;
	end = ((size / 2) + (size % 2)) + range;
}
