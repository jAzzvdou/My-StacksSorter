#include "push_swap.h"

#include <stdio.h>
int	smallest_in_a(t_pushswap *ps)
{
	int	smallest;

	smallest = ps->a->index;
	while (ps->a)
	{
		if (ps->a->index < smallest)
			smallest = ps->a->index;
		ps->a = ps->a->next;
	}
	return (smallest);
}

void	set_target(t_pushswap *ps)
{
	int	best_match_index;
	t_stack *tmp_a;

	while (ps->b)
	{
		best_match_index = 2147483647;
		tmp_a = ps->a;
		while (tmp_a)
		{
			if (tmp_a->index > ps->b->index
				&& tmp_a->index < best_match_index)
				best_match_index = tmp_a->index;
			tmp_a = tmp_a->next;
		}
		if (best_match_index == 2147483647)
			ps->b->target = smallest_in_a(ps); 
		else
			ps->b->target = best_match_index;
		ps->b = ps->b->next;
	}
}

void	make_moves2(t_pushswap *ps, int target, int index)
{
	if (index <= (stack_size(ps->b) / 2) && target <= (stack_size(ps->a) / 2))
	{
		while (ps->b && ps->b->index != index && ps->a->index != target)
			rr(ps);
		while (ps->b && ps->b->index != index)
			rb(ps);
		while (ps->a->index != target)
			ra(ps);
	}
	else if (index > (stack_size(ps->b) / 2) && target > (stack_size(ps->a) / 2))
	{
		while (ps->b->index != index && ps->a->index != target)
			rrr(ps);
		while (ps->b->index != index)
			rrb(ps);
		while (ps->a->index != target)
			rra(ps);
	}
	pa(ps);
}

int	true_value(int cost)
{
	if (cost < 0)
		cost = -cost;
	return (cost);
}

void	find_best_case(t_pushswap *ps)
{
	int	cost_sum;
	int	index;
	int	target;
	int	cheapest_sum;

	cheapest = 2147483647;
	cheapest_index = -1;
	while (ps->b)
	{
		cost_sum = true_value(cost_to_top(ps->b, ps->b->index)) + true_value(cost_to_top(ps->a, ps->b->target));
		if (cost_sum < cheapest_sum)
		{
			cheapest = cost_sum;
			index = ps->b->index;
			target = ps->b->target;
		}
		ps->b = ps->b->next;
	}
	make_moves2(ps, target, index);
}
