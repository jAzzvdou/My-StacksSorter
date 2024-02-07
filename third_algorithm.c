/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:02 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/07 19:01:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	maybe_push(t_pushswap *ps, int size, int flag)
{
	if (flag == 0)
		pb(ps);
	else
		pa(ps);
	size--;
	return (size);
}

static void	sort_b(t_pushswap *ps, int size)
{
	if (size == 1)
		pa(ps);
	else if (size == 2)
	{
		if (ps->b->value < ps->b->next->value)
			sb(ps);
		while (size--)
			pa(ps);
	}
	else if (size == 3)
	{
		while (size || !(ps->a->value < ps->a->next->value
			&& ps->a->next->value < ps->a->next->next->value))
		{
			if (size == 1 && ps->a->value > ps->a->next->value)
				sa(ps);
			else if (size == 1 || (size >= 2 && ps->b->value >
				ps->b->next->value) || (size == 3 &&
				ps->b->value > ps->b->next->next->value))
				size = maybe_push(ps, size, 1);
			else
				sb(ps);
		}
	}
}

static void	get_middle(int *stack, int size, int *pivot)
{
	int	i;
	int	*stack_tmp;

	stack_tmp =
	//CONTINUE
}

static void	quicksort_small(t_pushswap *ps, int size)
{
	if (size == 3 && stack_size(ps->a) == 3)
		first_algorithm(ps);
	else if (size == 2)
	{
		if (ps->a->value > ps->a->next->value)
			sa(ps);
	}
	else if (size == 3)
	{
		while (size != 3 || !(ps->a->value < ps->a->next->value
			&& ps->a->next->value < ps->a->next->next->value))
		{
			if (size == 3 && !(ps->a->value > ps->a->next->value
				&& ps->a->next->next->value))
				sa(ps);
			else if (size == 3 && !(ps->a->next->next->value >
				ps->a->value))
				size = maybe_push(ps, size, 0);
			else if (size++)
				pa(ps);
		}
	}
}

static int	quicksort(t_pushswap *ps, int size, int flag)
{
	int	pivot;
	int	elements;

	if (is_sorted(ps->b))
		while (size--)
			pa(ps);
	if (size <= 3)
	{
		sort_b(ps, size);
		return (1);
	}
	elements = size;
	if (!get_middle(ps->b, size, &pivot))
		return (0);
	while (size != elements / 2)
	{
		if (ps->b->value >= pivot && size--)
			pa(ps);
		else if (++flag)
			rb(ps);
	}
	while (elements / 2 != stack_size(ps->b) && flag--)
		rrb(ps);
	third_algorithm(ps, elements / 2 + elements % 2, 0);
	quicksort(ps, elements / 2, 0);
	return (1);
}

int	third_algorithm(t_pushswap *ps, int size, int flag)
{
	int	pivot;
	int	elements;

	elements = size;
	if (size <= 3)
	{
		quicksort_small(ps, size);
		return (1);
	}
	if (!get_middle(ps->a, size, &pivot) && !flag)
		return (0);
	while (size != elements / 2 + elements % 2)
	{
		if (ps->a->value < pivot && size--)
			pb(ps);
		else if (++flag)
			ra(ps);
	}
	while (elements / 2 + elements % 2 != stack_size(ps->a) && flag--)
		rra(ps);
	third_algorithm(ps, elements / 2 + elements % 2, 0);
	quicksort(ps, elements / 2, 0);
	return (1);
}
