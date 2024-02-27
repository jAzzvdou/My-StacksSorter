#include "push_swap.h"

#include <stdio.h>

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size >= 500)
		range = 18;
	else if (size >= 100)
		range = 6;
	return (range);
}

t_range_info	*start_range(t_pushswap *ps, int size)
{
	t_range_info	*r;

	r = malloc(sizeof(t_range_info));
	ps->start = ((size / 2)) - ps->range;
	ps->end = ((size / 2) + (size % 2)) + (ps->range - 1);
	r->size = ps->end - ps->start + 1;
	r->index_arr = malloc(sizeof(int) * r->size);
	int  ii = ps->start;
	int i = 0;
	while (i <= ps->end - ps->start)
		r->index_arr[i++] = ii++;
	return (r);

}

void	remove_from_range(t_pushswap *ps)
{
	int	*new_r;

	new_r = malloc(sizeof(int) * (ps->r->size - 1));
	int ii = 0;
	int i = 0;
	while (i < ps->r->size)
	{
		if (ps->a && ps->r->index_arr[i] == ps->a->index)
			i++;
		else
			new_r[ii++] = ps->r->index_arr[i++];
	}
	free(ps->r->index_arr);
	ps->r->index_arr = new_r;
}

t_range_info	*next_range(t_pushswap *ps, int *sorted_arr, int size)
{
	t_range_info	*new_r;

	new_r = malloc(sizeof(t_range_info));
	new_r->start = ps->start - ps->range;
	if (new_r->start < 0)
		new_r->start = 0;
	new_r->end = ps->end + ps->range;
	if (new_r->end > size - 1)
		new_r->end = size - 1;
	int i = new_r->start;
	int ii = ps->start;
	while (i < ii)
		i++;
	i -= new_r->start;
	ii = ps->end;
	while (ii <= new_r->end)
		ii++;
	ii -= ps->end;
	new_r->size = i + ii - 1;
	new_r->index_arr = malloc(sizeof(int) * new_r->size);
	i = 0;
	ii = new_r->start - 1;
	int iii = ps->start;
	while (ii < iii - 1)
		new_r->index_arr[i++] = sorted_arr[ii++];
	ii = ps->end;
	iii = new_r->end;
	while (ii < iii)
		new_r->index_arr[i++] = sorted_arr[ii++];
	ps->start = new_r->start;
	ps->end = new_r->end;
	return (new_r);
}
