#include "push_swap.h"

#include <stdio.h>

int	cheapest_in_range(t_pushswap *ps, int start, int end)
{
	int	i;
	int	tmp;
	int	cost;
	int	smallest;

	smallest = 2147483647;
	cost = 0;
	i = start - 1;
        while (++i <= end)
        {
                tmp = cost_to_top(ps->a, i);
		printf("try: %d.\n", tmp);
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
	int size = stack_size(ps->a);
	int range = set_range(size);
	int start = ((size / 2) + (size % 2)) - range - 1;
	int end = ((size / 2) + (size % 2)) + range - 1;

	int *array = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, array, size);

	int cost = cheapest_in_range(ps, start, end);

	printf("pivot: %d.\n", (size / 2));
	printf("cost: %d.\n", cost);
}
