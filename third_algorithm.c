/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:23 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/11 13:06:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	make_moves(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rra(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			ra(ps);
	}
}

int	smallest_in_range(t_pushswap *ps)
{
	int	i;
	int	smallest;

	smallest = ps->r->index_arr[0];
	i = 0;
	while (ps->r->index_arr[i])
	{
		if (ps->r->index_arr[i] < smallest)
			smallest = ps->r->index_arr[i];
		i++;
	}
	return (smallest);
}

void	a_to_b(t_pushswap *ps, int *sorted_arr, int size)
{
	while (ps->a)
	{
		while (ps->r->size)
		{
			make_moves(ps, cheapest_in_range(ps));
			remove_from_range(ps);
			ps->r->size--;
			pb(ps);
			if (ps->b && ps->b->index < ps->smallest_index)
				rb(ps);
		}
		free(ps->r->index_arr);
		free(ps->r);
		ps->r = next_range(ps, sorted_arr, size);
	}
	free(ps->r->index_arr);
	free(ps->r);
}

/////////////////////////////////////////////////////////////////////////////

int	cheapest_in_range2(t_pushswap *ps, int range)
{
	int	i;
	int	tmp;
	int	cost;
	int	smallest;
	smallest = 2147483647;
	cost = 0;
	i = -1;
	while (++i < range)
	{
		tmp = cost_to_top(ps->b, stack_size(ps->b) - i - 1);
		if (tmp < 0)
		{
			if (-tmp < smallest)
			{
				smallest = -tmp;
				cost = tmp;
			}
		}
		else if (tmp < smallest)
		{
			smallest = tmp;
			cost = tmp;
		}
	}
	return (cost);
}

void	make_moves2(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rrb(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			rb(ps);
	}
	pa(ps);
}

void	third_algorithm(t_pushswap *ps, int size)
{
	int	*sorted_arr;

	sorted_arr = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, sorted_arr, size);
	ps->range = set_range(size);
	ps->r = start_range(ps, size);
	ps->smallest_index = smallest_in_range(ps);
	a_to_b(ps, sorted_arr, size);
	ps->range = 5;
	while (ps->b)
	{
		size = stack_size(ps->b);
		sorted_arr = bubblesort(stack_to_array(ps->b), size);
		set_index(ps->b, sorted_arr, size);
		make_moves2(ps, cheapest_in_range2(ps, ps->range));
		ps->range--;
		if (!ps->range)
		{
			second_algorithm(ps);
			ps->range = 5;
		}
	}
}
