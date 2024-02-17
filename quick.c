#include "push_swap.h"

#include <stdio.h>

int     *stack_to_array(t_stack *stack)
{
        int     i;
        int     *array;
        int     size;

        size = stack_size(stack);
        array = malloc(sizeof(int) * size);
        i = -1;
        while (++i < size)
        {
                array[i] = stack->value;
                stack = stack->next;
        }
        return (array);
}

int     *bubblesort(int *stack, int size)
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
        return (stack);
}

int     find_pivot(t_stack *stack, int size)
{
	int     *array;
	int     pivot;

	array = stack_to_array(stack);
	array = bubblesort(array, size);
	pivot = array[size / 2];
	free(array);
	return (pivot);
}

void	sort_b(t_pushswap *ps, int size)
{
	if (size == 1)
		pa(ps);
	else if (size == 2)
	{
		if (ps->b && ps->b->value < ps->b->next->value)
			sb(ps);
		while (ps->b)
			pa(ps);
	}
	else if (size == 3)
	{
		while (size || !(ps->a->value < ps->a->next->value
			&& ps->a->next->value < ps->a->next->next->value))
		{
			if (size == 1 && ps->a->value > ps->a->next->value)
				sb(ps);
			else if (size == 1 || (ps->b->next && (size >= 2 && ps->b->value > ps->b->next->value))
				|| (ps->b->next->next && (size == 3 && ps->b->value > ps->b->next->next->value)))
			{
				pa(ps);
				size--;
			}
			else
				sb(ps);
		}
	}
}

void	sort_a(t_pushswap *ps, int size)
{
	if (size == 3 && ps->size_a == 3)
		first_algorithm(ps);
	else if (size == 2)
	{
		if (ps->a->value > ps->a->next->value)
			sa(ps);
	}
	else if (size == 3)
	{
		while (size != 3 || (ps->a->next->next && !(ps->a->value < ps->a->next->value
				&& ps->a->next->value < ps->a->next->next->value)))
		{
			if (size == 3 && ps->a->value > ps->a->next->value)
				sa(ps);
			else if (size == 3 && !(ps->a->next->next->value > ps->a->value
					&& ps->a->next->next->value > ps->a->next->value))
			{
				pb(ps);
				size--;
			}
			else if (ps->a->value > ps->a->next->value)
				sa(ps);
			else if (size++)
				ra(ps);
		}
	}
}

void	quick_b(t_pushswap *ps, int size, int flag)
{
	int	pivot;
	int	elements;

	if (is_sorted(ps->a) && (ps->b))
		while (ps->b)
			pa(ps);
	if (size <= 3)
	{
		sort_b(ps, size);
		return ;
	}
	pivot = find_pivot(ps->b, size);
	if (!pivot)
		return ;
	elements = size;
	while (size != elements / 2)
	{
		if (ps->b->value >= pivot && size--)
			pa(ps);
		else if (++flag)
			rb(ps);
	}
	while (elements / 2 != ps->size_b && flag--)
		rrb(ps);
	quick_a(ps, elements / 2 + elements % 2, 0);
	quick_b(ps, elements / 2, 0);
}

void	quick_a(t_pushswap *ps, int size, int flag)
{
	int	pivot;
	int	elements;

	if (is_sorted(ps->a) && !(ps->b))
		return ;
	if (size <= 3)
	{
		sort_a(ps, size);
		return ;
	}
	pivot = find_pivot(ps->a, size);
	if (!pivot && !flag)
		return ;
	elements = size;
	while (size != elements / 2 + elements % 2)
	{
		if (ps->a->value < pivot && size--)
			pb(ps);
		else if (++flag)
			ra(ps);
	}
	while (elements / 2 + elements % 2 != ps->size_a && flag--)
		rra(ps);
	quick_a(ps, elements / 2 + elements % 2, 0);
	quick_b(ps, elements / 2, 0);
}
