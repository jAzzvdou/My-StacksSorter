/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:24:46 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/05 17:25:06 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algorithm(t_pushswap *ps)
{
	if (ps->a->value < ps->a->next->value
		&& ps->a->value < ps->a->next->next->value
		&& ps->a->next->value > ps->a->next->next->value)
	{
		sa(ps);
		ra(ps);
	}
	else if (ps->a->value > ps->a->next->value
		&& ps->a->value < ps->a->next->next->value
		&& ps->a->next->value < ps->a->next->next->value)
		sa(ps);
	else if (ps->a->value < ps->a->next->value
		&& ps->a->value > ps->a->next->next->value
		&& ps->a->next->value > ps->a->next->next->value)
		rra(ps);
	else if (ps->a->value > ps->a->next->value
		&& ps->a->value > ps->a->next->next->value
		&& ps->a->next->value < ps->a->next->next->value)
		ra(ps);
	else
	{
		sa(ps);
		rra(ps);
	}
}
