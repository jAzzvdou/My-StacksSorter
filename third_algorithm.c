/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:23 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/07 17:52:36 by jazevedo         ###   ########.fr       */
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

void	order(t_pushswap *ps, int *up, int *down)
{
	while (*up > 1)
	{
		ra(ps);
		*up = *up - 1;
		*down = *down + 1;
	}
	pa(ps);
	if (*up == 1)
		sa(ps);
}

int     is_on_stack(t_stack *stack, int index, int size)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < size && tmp)
	{
		if (tmp->index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	sort_a(t_pushswap *ps, int *up, int *down, int biggest)
{
	if (stack_size(ps->a) == 0)
		return (0);
	if (is_on_stack(ps->a, biggest, *up) != -1)
	{
		*up = *up - 1;
		return (1);
	}
	else if (stack_size(ps->a) && last_index(ps->a) == biggest)
	{
		ra(ps);
		*down = *down - 1;
		return (1);
	}
	return (0);
}

int	can_push(t_pushswap *ps, int *up, int *down)
{
	if (stack_size(ps->b) == 0)
		return (0);
	if (ps->b->index < ps->a->index
		&& (*down == 0 || ps->b->index > last_index(ps->a)))
	{
		pa(ps);
		*up = *up + 1;
		return (1);
	}
	else if (*down == 0 || ps->b->index > last_index(ps->a))
	{
		while (*up && ps->b->index > ps->a->index)
		{
			ra(ps);
			*up = *up - 1;
			*down = *down + 1;
		}
		pa(ps);
		*up = *up + 1;
		return (1);
	}
	return (0);
}

int	to_top(t_pushswap *ps, int biggest)
{
	int	biggest_i;

	if (stack_size(ps->b) == 0)
		return (0);
	biggest_i = is_on_stack(ps->b, biggest, stack_size(ps->b));
	if (biggest_i != -1 && biggest_i < stack_size(ps->b) / 2)
	{
		rb(ps);
		biggest_i--;
		return (1);
	}
	else if (biggest_i != -1 && biggest_i < stack_size(ps->b))
	{
		rrb(ps);
		biggest_i++;
		return (1);
	}
	else
		return (0);
}

void	b_to_a(t_pushswap *ps, int *sorted_arr, int size)
{
	int	i;
	int	up;
	int	down;

	up = 0;
	down = 0;
	i = size - 1;
	while (stack_size(ps->b) || up || down)
	{
		if (sort_a(ps, &up, &down, sorted_arr[i]))
			i--;
		else if (stack_size(ps->b) && sorted_arr[i] == ps->b->index)
		{
			order(ps, &up, &down);
			i--;
		}
		else if (can_push(ps, &up, &down))
			continue ;
		else if (to_top(ps, sorted_arr[i]))
			continue ;
		else
			i--;
	}
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
	pa(ps);
	pa(ps);
	pa(ps);
	b_to_a(ps, sorted_arr, stack_size(ps->b)); 	
}
