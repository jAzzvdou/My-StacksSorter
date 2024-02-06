/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:29:45 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/06 15:42:00 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_pushswap *ps)
{
	t_stack	*a;
	int		i;
	int		position;
	int		smallest;

	a = ps->a;
	smallest = ps->a->value;
	position = 1;
	i = 1;
	while (a)
	{
		if (a->value < smallest)
		{
			smallest = a->value;
			position = i;
		}
		a = a->next;
		i++;
	}
	return (position);
}

static void	four_elements(t_pushswap *ps)
{
	int	small;

	small = find_smallest(ps);
	if (small == 2)
		ra(ps);
	else if (small == 3)
	{
		rra(ps);
		rra(ps);
	}
	else if (small == 4)
		rra(ps);
	pb(ps);
	if (!is_sorted(ps->a))
		first_algorithm(ps);
	pa(ps);
}

static void	five_elements(t_pushswap *ps)
{
	int	small;

	small = find_smallest(ps);
	if (small == 2)
		ra(ps);
	else if (small == 3)
	{
		ra(ps);
		ra(ps);
	}
	else if (small == 4)
	{
		rra(ps);
		rra(ps);
	}
	else if (small == 5)
		rra(ps);
	pb(ps);
	second_algorithm(ps);
	pa(ps);
}

void	second_algorithm(t_pushswap *ps)
{
	if (stack_size(ps->a) == 4)
		four_elements(ps);
	else if (stack_size(ps->a) == 5)
		five_elements(ps);
}
