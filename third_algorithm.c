/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:48:49 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 17:15:26 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inside_stack(t_stack *stack, int value, int size)
{
	int	i;
	int	nb;
	t_node	*node;

	node = stack->top;
	nb = 0;
	i = 0;
	while (i < size && node)
	{
		nb = node->value;
		if (nb == value)
			return (i);
		i++;
		node = node->prev;
	}
	return (-1);
}

int	inside_range(t_pushswap *ps, int start, int end)
{
	int	i;
	
	i = start;
	while (i <= end)
	{
		if (ps->a->top->value == ps->sorted[i])
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

void	a_to_b(t_pushswap *ps, int size)
{
	int	start;
	int	end;
	int	ivalue;
	int	*pushed_value;

	pushed_value = ft_calloc(size, sizeof(int));
	set_chunk(&start, &end, size);
	while (ps->a->size > 3)
	{
		while (!is_chunk_sent(pushed_value, start, end) && ps->a->size)
		{
			ivalue = inside_range(ps, start, end);
			if (ivalue != -1 && !pushed_value[ivalue])
			{
				pushed_value[ivalue] = 1;
				pb(ps);
				if (ps->b->top->value < (size / 2))
					rb(ps);
			}
			else
				ra(ps);
			update_chunk(pushed_value, &start, &end, size);
		}
	}
	if (!is_sorted(ps->a))
		first_algorithm(ps);
	free(pushed_value);
}

////////////////////////////////////////////////////////////////////////////////////

int	sort_a(t_pushswap *ps, int *up, int *down, int highest)
{
	if (ps->a->size == 0)
		return (0);
	if (inside_stack(ps->a, highest, *up) != -1)
	{
		*up = *up - 1;
		return (1);
	}
	else if (ps->a->size && ps->a->bot->value == highest)
	{
		rra(ps);
		*down = *down - 1;
		return (1);
	}
	return (0);
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

int	canpush(t_pushswap *ps, int *up, int *down)
{
	if (!ps->b->size)
		return (0);
	if (ps->b->top->value < ps->a->top->value
		&& (*down == 0 || ps->b->top->value > ps->a->bot->value))
	{
		pa(ps);
		*up = *up + 1;
		return (1);
	}
	else if (*down == 0 || ps->b->top->value > ps->a->bot->value)
	{
		while (*up && ps->b->top->value > ps->a->top->value)
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

int	to_top(t_pushswap *ps, int highest)
{
	int	ihighest;

	if (ps->b->size == 0)
		return (0);
	ihighest = inside_stack(ps->b, highest, ps->b->size);
	if (ihighest != -1 && ihighest < (ps->b->size / 2))
	{
		rb(ps);
		ihighest--;
		return (1);
	}
	else if (ihighest != -1 && ihighest < ps->b->size)
	{
		rrb(ps);
		ihighest++;
		return (1);
	}
	else
		return (0);

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
		if (sort_a(ps, &up, &down, ps->sorted[i]))
			i--;
		else if (ps->b->size && ps->sorted[i] == ps->b->top->value)
		{
			order(ps, &up, &down);
			i--;
		}
		else if (canpush(ps, &up, &down))
			continue ;
		else if (to_top(ps, ps->sorted[i]))
			continue ;
		else
			i--;
	}
}

void	t(t_pushswap *ps)
{
	a_to_b(ps, ps->a->size);
	b_to_a(ps, ps->b->size);
}
