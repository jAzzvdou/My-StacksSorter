#include "push_swap.h"

int	push_and_rotate(t_pushswap *ps, int size)
{
	pb(ps);
	if (ps->b->top->index < (size / 2))
		rb(ps);
	return (1);
}

int	inside_range(t_pushswap *ps, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (ps->a->top->index == i)
			return (i);
		i++;
	}
	return (-1);
}

int	is_chunk_sent(int *pushed_value, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (pushed_value[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_chunk(int *pushed_value, int *start, int *end, int size)
{
	int	i;

	i = *start;
	while (i < (size / 2))
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == (size / 2))
		*start = *start - (size / set_range(size));
	i = size / 2;
	while (i < *end)
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == *end && pushed_value[i])
		*end = *end + (size / set_range(size));
	if (*start < 0)
		*start = 0;
	if (*end >= (size - 3))
		*end = size - 4;
}
