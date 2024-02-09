/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:02 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/09 00:17:23 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_choice(t_pushswap *ps, int size, int flag)
{
	if (flag == 0)
		pb(ps);
	else
		pa(ps);
	size--;
	return (size);
}

void    bubblesort(int *stack, int size)
{
        int     i;
        int     ii;
        int     tmp;

        i = -1;
        while (++i < size)
        {
                ii = i;
                while (++ii < size)
                {
                        if (stack[i] > stack[ii])
                        {
                                tmp = stack[i];
                                stack[i] = stack[ii];
                                stack[ii] = tmp;
                        }
                }
        }
}

int	find_pivot(t_stack *stack, int size, int *pivot)
{
	int	i;
	int	*stack_copy;

	stack_copy = (int *)malloc(sizeof(int) * size);
	if (!stack_copy)
		return (0);
	i = -1;
	while (++i < size)
	{
		stack_copy[i] = stack->value;
		stack = stack->next;
	}
	bubblesort(stack_copy, size);
	*pivot = stack_copy[size / 2];
	free(stack_copy);
	return (1);
}

int     sort_b(t_pushswap *ps, int size)
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
                while (size || !(ps->a->value < ps->a->next->value && ps->a->next->value < ps->a->next->next->value))
                {
                        if (size == 1 && ps->a->value > ps->a->next->value)
                                sa(ps);
                        else if (size == 1 || (size >= 2 && ps->b->value > ps->b->next->value)
                                || (size == 3 && ps->b->value > ps->b->next->next->value))
                                size = push_choice(ps, size, 1);
                        else
                                sb(ps);
                }
        }
        return (0);
}

int     quicksort(t_pushswap *ps, int size, int flag)
{
        int     pivot;
        int     nodes;

        if (is_sorted(ps->b) && !flag)
                while (size--)
                        pa(ps);
        if (size <= 3)
        {
                sort_b(ps, size);
                return (1);
        }
        nodes = size;
        if (!find_pivot(ps->b, size, &pivot))
                return (0);
        while (size != nodes / 2)
        {
                if (ps->b->value >= pivot && size--)
                        pa(ps);
                else if (++flag)
                        rb(ps);
        }
        while (nodes / 2 != stack_size(ps->a) && flag--)
                rrb(ps);
        third_algorithm(ps, nodes / 2 + nodes % 2, 0);
        quicksort(ps, nodes / 2, 0);
        return (1);
}

void    sort(t_pushswap *ps, int size)
{
        if (size == 2)
	{
                if (ps->a->value > ps->a->next->value)
                        sa(ps);
	}
        else if (size == 3 && stack_size(ps->a) == 3)
                first_algorithm(ps);
        else if (size == 3)
        {
                while (size != 3 || !(ps->a->value < ps->a->next->value
                                && ps->a->next->value < ps->a->next->next->value))
                {
                        if (size == 3 && ps->a->value > ps->a->next->value
                                && ps->a->next->next->value)
                                sa(ps);
                        else if (size == 3 && !(ps->a->next->next->value > ps->a->value
                                        && ps->a->next->next->value > ps->a->next->value))
                                size = push_choice(ps, size, 0);
                        else if (ps->a->value > ps->a->next->value)
                                sa(ps);
                        else if (size++)
                                pa(ps);
                }
        }
}

int	third_algorithm(t_pushswap *ps, int size, int flag)
{
	int	pivot;
	int	nodes;

	if (is_sorted(ps->a))
		return (1);
	nodes = size;
	if (size <= 3)
	{
		sort(ps, size);
		return (1);
	}
	if (!find_pivot(ps->a, size, &pivot) && !flag)
		return (0);
	while (size != nodes / 2 + nodes % 2)
	{
		if (ps->a->value < pivot && size--)
			pb(ps);
		else if (++flag)
			ra(ps);
	}
	while (nodes / 2 + nodes % 2 != stack_size(ps->a) && flag--)
		rra(ps);
	third_algorithm(ps, nodes / 2 + nodes % 2, 0);
	quicksort(ps, nodes / 2, 0);
	return (1);
}
