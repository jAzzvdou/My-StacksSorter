/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:43:05 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 23:02:20 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algorithm(t_pushswap *ps)
{
	int	f;
	int	s;
	int	t;

	f = ps->a->top->index;
	s = ps->a->top->prev->index;
	t = ps->a->top->prev->prev->index;
	if (f < s && f < t && s > t)
	{
		sa(ps);
		ra(ps);
	}
	else if (f > s && f < t && s < t)
		sa(ps);
	else if (f < s && f > t && s > t)
		rra(ps);
	else if (f > s && f > t && s < t)
		ra(ps);
	else
	{
		sa(ps);
		rra(ps);
	}
}
