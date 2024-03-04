/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:23 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/04 16:51:08 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	biggest_index(t_stack *stack)
{
	int	biggest;

	biggest = -1;
	while (stack)
	{
		if (stack->index > biggest)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
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

int	last_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int	cost_to_push(t_pushswap *ps, t_stack *stack, int index)
{
	int	lowest_index;

	lowest_index = 2147483647;
	while (stack)
	{
		if (stack->index > index && stack->index < lowest_index)
			lowest_index = stack->index;
		stack = stack->next;
	}
	int cost = cost_to_top(ps->a, lowest_index);
	return (cost);
}

void	b_to_a(t_pushswap *ps, int biggest)
{
	int cost_a = cost_to_push(ps, ps->a, biggest);
	int cost_b = cost_to_top(ps->b, biggest);
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a++ < 0 && cost_b++ < 0)
			rrr(ps);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a-- > 0 && cost_b-- > 0)
			rr(ps);
	}
	if (cost_a < 0)
	{
		while (cost_a++ < 0)
			rra(ps);
	}
	else if (cost_a > 0)
	{
		while (cost_a-- < 0)
			ra(ps);
	}
	if (cost_b < 0)
	{
		while (cost_b++ < 0)
			rrb(ps);
	}
	else if (cost_b > 0)
	{
		while (cost_b-- > 0)
			rb(ps);
	}
}

#include <stdio.h>

void	third_algorithm(t_pushswap *ps, int size)
{
	int	*sorted_arr;

	sorted_arr = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, sorted_arr, size);
	ps->range = set_range(size);
	ps->r = start_range(ps, size);
	ps->smallest_index = smallest_in_range(ps);
	a_to_b(ps, sorted_arr, size);
	int cost = cost_to_top(ps->b, biggest_index(ps->b));
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
	while (ps->b->index < ps->a->index)
		pa(ps);
	while (ps->b)
	{
		b_to_a(ps, biggest_index(ps->b));
		pa(ps);
	}
}
