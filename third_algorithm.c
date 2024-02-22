#include "push_swap.h"

#include <stdio.h>

void	third_algorithm(t_pushswap *ps, int size)
{
	int range = set_range(size);

	int *array = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, array, size);

	int start = (size / 2) - range;
	int end = (size / 2) + range;
	printf("start: %d.\n", start);
	printf("end: %d.\n", end);
}
