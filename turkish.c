#include "push_swap.h"

#include <stdio.h>
int	smallest_in_a(t_stack *a)
{
	int	smallest;

	smallest = a->index;
	while (a)
	{
		if (a->index < smallest)
			smallest = a->index;
		a = a->next;
	}
	return (smallest);
}

void	set_target(t_stack *a, t_stack *b)
{
	int	best_match_index;
	t_stack	*tmp_a;

	while (b)
	{
		best_match_index = 2147483647;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->index > b->index
				&& tmp_a->index < best_match_index)
				best_match_index = tmp_a->index;
			tmp_a = tmp_a->next;
		}
		if (best_match_index == 2147483647)
			b->target = smallest_in_a(tmp_a); 
		else
			b->target = best_match_index;
		b = b->next;
	}
}

void	make_moves2(t_pushswap *ps, int *cost_ab)
{
	if (cost_ab[0] > 0 && cost_ab[1] > 0)
	{
		while (cost_ab[0] > 0 && cost_ab[1] > 0)
		{
			cost_ab[0]--;
			cost_ab[1]--;
			rr(ps);
		}
		while (cost_ab[0] > 0)
		{
			cost_ab[0]--;
			ra(ps);
		}
		while (cost_ab[1] > 0)
		{
			cost_ab[1]--;
			rb(ps);
		}
	}
	if (cost_ab[0] < 0 && cost_ab[1] < 0)
	{
		while (cost_ab[0] < 0 && cost_ab[1] < 0)
		{
			cost_ab[0]++;
			cost_ab[1]++;
			rrr(ps);
		}
		while (cost_ab[0] < 0)
		{
			cost_ab[0]++;
			ra(ps);
		}
		while (cost_ab[1] < 0)
		{
			cost_ab[1]++;
			rb(ps);
		}
	}
	pa(ps);
}

int	true_value(int cost)
{
	if (cost < 0)
		cost = -cost;
	return (cost);
}

void	find_best_match(t_pushswap *ps, t_stack *b)
{
	int	cost_ab[2];
	int	cost_sum;
	int	cheapest_sum;

	cheapest_sum = 2147483647;
	while (b)
	{
		cost_sum = true_value(cost_to_top(ps->b, b->index)) + true_value(cost_to_top(ps->a, b->target));
		if (cost_sum < cheapest_sum)
		{
			cheapest_sum = cost_sum;
			cost_ab[0] = cost_to_top(ps->a, b->target);
			cost_ab[1] = cost_to_top(ps->b, b->index);
		}
		b = b->next;
	}
	make_moves2(ps, cost_ab);
}
