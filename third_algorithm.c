#include "push_swap.h"

void	a_to_b(t_pushswap *ps, int size)
{
	int	start;
	int	end;
	int	ivalue;
	int	*pushed_value;

	pushed_value = my_calloc(size, sizeof(int));
	set_chunk(&start, &end, size);
	while (ps->a->size > 3)
	{
		while (!is_chunk_sent(pushed_value, start, end) && ps->a->size)
		{
			ivalue = inside_range(ps, start, end);
			if (ivalue != -1 && !pushed_value[ivalue])
				pushed_value[ivalue] = push_and_rotate(ps, size);
			else
				ra(ps);
			update_chunk(pushed_value, &start, &end, size);
		}
	}
	if (!is_sorted(ps->a))
		first_algorithm(ps);
	free(pushed_value);
}

void	b_to_a(t_pushswap *ps, int size)
{
	int	i;
	int	up;
	int	down;

	up = 0;
	down = 0;
	i = size - 1;
	while (ps->b->size || up > 0 || down > 0)
	{
		if (sort_a(ps, &up, &down, i))
			i--;
		else if (ps->b->size && i == ps->b->top->index)
		{
			order(ps, &up, &down);
			i--;
		}
		else if (canpush(ps, &up, &down))
			continue ;
		else if (to_top(ps, i))
			continue ;
		else
			i--;
	}
}

void	third_algorithm(t_pushswap *ps)
{
	a_to_b(ps, ps->a->size);
	b_to_a(ps, ps->b->size);
}
