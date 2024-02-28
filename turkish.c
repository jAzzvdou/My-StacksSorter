#include "push_swap.h"

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
	int	best_case = 2147483647;
	t_stack *tmp;
	
	print_stacks(ps);
	while (ps->b)
	{
		tmp = ps->a;
		while (tmp)
		{
			if (tmp->index > ps->b->index
				&& tmp->index < best_case)
				best_case = tmp->index;
			tmp = tmp->next;
		}
		if (best_case == 2147483647)
			ps->b->target = smallest_in_a(ps); 
		else
			ps->b->target = best_case;
		ps->b = ps->b->next;
	}
}

#include <stdio.h>
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
	int	temp;
	int	cheapest;
	int	cheapest_index;
	int	cheapest_target;

	cheapest = 2147483647;
	cheapest_index = -1;
	while (ps->b)
	{
		temp = true_value(cost_to_top(ps->b, ps->b->index)) + true_value(cost_to_top(ps->a, ps->b->target));
		if (temp < cheapest)
		{

			cheapest = temp;
			cheapest_index = ps->b->index;
			cheapest_target = ps->b->target;
		}
		ps->b = ps->b->next;
	}
	make_moves2(ps, cheapest_target, cheapest_index);
}
