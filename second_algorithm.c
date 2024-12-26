#include "push_swap.h"

int	find_lowest(t_pushswap *ps)
{
	int		i;
	int		pos;
	int		lowest;
	t_node	*a;

	a = ps->a->top;
	lowest = a->index;
	pos = 1;
	i = 1;
	while (a)
	{
		if (a->index < lowest)
		{
			lowest = a->index;
			pos = i;
		}
		a = a->prev;
		i++;
	}
	return (pos);
}

static void	four_elements(t_pushswap *ps)
{
	int	lowest;

	lowest = find_lowest(ps);
	if (lowest == 2)
		ra(ps);
	else if (lowest == 3)
	{
		rra(ps);
		rra(ps);
	}
	else if (lowest == 4)
		rra(ps);
	pb(ps);
	if (!is_sorted(ps->a))
		first_algorithm(ps);
	pa(ps);
}

static void	five_elements(t_pushswap *ps)
{
	int	lowest;

	lowest = find_lowest(ps);
	if (lowest == 2)
		ra(ps);
	else if (lowest == 3)
	{
		ra(ps);
		ra(ps);
	}
	else if (lowest == 4)
	{
		rra(ps);
		rra(ps);
	}
	else if (lowest == 5)
		rra(ps);
	pb(ps);
	four_elements(ps);
	pa(ps);
}

void	second_algorithm(t_pushswap *ps)
{
	if (ps->a->size == 4)
		four_elements(ps);
	else if (ps->a->size == 5)
		five_elements(ps);
}
