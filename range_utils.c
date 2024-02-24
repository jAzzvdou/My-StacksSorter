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

t_range	*start_range(t_pushswap *ps, int size)
{
	t_range_info	*r;

	r = malloc(sizeof(t_range));
	r->start = ((size / 2)) - ps->range;
	r->end = ((size / 2) + (size % 2)) + (ps->range - 1);
	r->size = range->end - range->start + 1;
	r->index_arr = malloc(sizeof(int) * (r->end - r->start) + 1);
	int  ii = r->start;
	int i = 0;
	while (i <= r->end - r->start)
		r->index_arr[i++] = ii++;
	return (r);

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

void	remove_from_range(t_pushswap *ps)
{
	int	*new_r;

	new_r = malloc(sizeof(int) * (ps->r->size - 1));
	int ii = 0;
	int i = 0;
	while (i < ps->r->size)
	{
		if (ps->r->index_arr[i] == ps->a->index)
			i++;
		else
			new_range[ii++] = ps->r->index_arr[i++];
	}
	free(ps->r->index_arr);
	ps->r->index_arr = new_r;
}
