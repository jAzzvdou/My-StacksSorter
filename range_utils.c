#include "push_swap.h"

#include <stdio.h>

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size >= 500)
		range = 20;
	else if (size >= 100)
		range = 6;
	return (range);
}

t_range	*start_range(int size)
{
	t_range	*range;

	range = malloc(sizeof(t_range));
	range->start = ((size / 2)) - set_range(size);
	range->end = ((size / 2) + (size % 2)) + (set_range(size) - 1);
	range->size = range->end - range->start + 1;
	range->array = malloc(sizeof(int) * (range->end - range->start) + 1);
	int  j = range->start;
	int i = 0;
	while (i <= range->end - range->start)
		range->array[i++] = j++;
	return (range);

}

void	restart_range(t_pushswap *ps)
{
	t_range	*range;

	range = malloc(sizeof(t_range));
	range->start = ps->r->start - ps->range / 2;
	range->end = ps->r->start - ps->range / 2;
	range->array = malloc(sizeof(int) * (range->end - range->start) - 1);
	int  j = range->start;
	int i = 0;
	while(i <= range->end - range->start)
	{
		range->array[i] = ps->r->array[j];
		i++;
		j++;
	}
	free(ps->r->array);
	free(ps->r);
	ps->r = range;
}

void	rebuild_range(t_pushswap *ps)
{
	int	*new_range;

	new_range = malloc(sizeof(int) * (ps->r->size - 1));
	int i = 0;
	int j = 0;
	while (i < ps->r->size)
	{
		if (ps->r->array[i] == ps->a->index)
			i++;
		else
			new_range[j++] = ps->r->array[i++];
	}
	free(ps->r->array);
	ps->r->array = new_range;
}
