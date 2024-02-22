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
	while (stack_size(ps->a) > 1)
	{
		while (stack_size(ps->b) < total)
		{
			int i = start;
			int finded = 0;
			int rot = 0;
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
				if (ps->a && ps->b && ps->b->next && ps->b->value < ps->b->next->value)
				{
					rr(ps);
					rot = 1;
				}
				else
					ra(ps);
			}
			if (!rot && ps->b && ps->b->next && ps->b->value < ps->b->next->value)
				rb(ps);
		}
		start -= range;
		end += range;
		total = end - start + 1;
	}
}
