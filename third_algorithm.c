#include "push_swap.h"

#include <stdio.h>

void	third_algorithm(t_pushswap *ps)
{
	int size = stack_size(ps->a);
	int range = set_range(size);

	int *array = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, array, size);

	int start = (size / 2) - range;
	int end = (size / 2) + range;
	int total = end - start + 1;
	while (stack_size(ps->b) != total)
	{
		int i = start;
		while (i <= end)
		{
			if (ps->a->value == array[i])
				pb(ps);
			i++;
		}
		if (ps->a && ps->b && ps->b->next && ps->b->next->value > ps->b->value)
			rr(ps);
		else
			ra(ps);
	}
}
