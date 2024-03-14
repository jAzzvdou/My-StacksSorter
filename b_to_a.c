/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:42:48 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 15:42:51 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inside_stack(t_stack *stack, int value, int size)
{
	int		i;
	int		nb;
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
