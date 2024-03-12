/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:23 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/12 00:19:25 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pivotcmp(t_pushswap *ps, int index_pivot, int size)
{
	while (size--)
	{
		if (ps->a->index <= index_pivot)
			pb(ps);
		else
			ra(ps);
	}
}

void	third_algorithm(t_pushswap *ps, int size)
{
	int	*sorted_arr;

	sorted_arr = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, sorted_arr, size);
	pivotcmp(ps, size / 2, size);
}
