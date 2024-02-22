#include "push_swap.h"

#include <stdio.h>

void	third_algorithm(t_pushswap *ps, int size)
{
	int range = set_range(size);

	int *array = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, array, size);

	int start = (size / 2) - range;
	int end = (size / 2) + range;
	while (stack_size(ps->a) > 1)
	{
		int finded = 0;
		int i = start;
		while (i <= end)
		{
			if (ps->a->index == array[i])
			{
				pb(ps);
				finded = 1;
			}
			i++;
		}
		if (!finded)
		{
			if (stack_size(ps->b) > 1
				&& ps->b->index < ps->b->next->index)
				rr(ps);
			else
				ra(ps);
		}
		start -= range;
		end += range;
	}
}
