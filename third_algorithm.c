/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:23 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/06 09:56:24 by jazevedo         ###   ########.fr       */
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

///////////////////////////////////////////////////////////////////////

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

int	last_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

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

void	print_target(t_stack *b)
{
	while (b)
	{
		printf("b->index: %d, b->target: %d\n", b->index, b->target);
		b = b->next;
	}
}

int	best_cost(t_pushswap *ps)
{
	int	cost;
	int	best_cost;
	t_stack	*tmp_b;

	best_cost = 2147483647;
	tmp_b = ps->b;
	while (tmp_b)
	{
		cost = cost_to_push(ps, ps->a, tmp_b->index);
		if (cost < best_cost)
			best_cost = cost;
		tmp_b = tmp_b->next;
	}
	return (best_cost);
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

	int last = -1;
	int locked = 0;
	pa(ps);
	while (ps->b->index != last)
	{
		while (ps->b->index < ps->a->index)
		{
			if (ps->b->next->index < ps->b->index)
				sb(ps);
			pa(ps);
		}
		if (ps->b->index > last_index(ps->a))
		{
			pa(ps);
			ra(ps);
		}
		if (ps->b->index > ps->a->index && ps->b->index < ps->a->next->index)
		{
			pa(ps);
			sa(ps);
		}
		else if (ps->b->index > ps->a->index && ps->b->index < last_index(ps->a))
		{
			if (!locked)
			{
				locked = 1;
				last = ps->b->index;
			}
			rb(ps);
		}
	}
	set_target(ps->a, ps->b);
	// preciso criar uma função que calcule qual o melhor custo de empilhar index b em cima do index a.
	int cost = best_cost(ps);
	printf("Cost: %d\n", cost);
}
