/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:00:36 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 02:49:19 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	reverse_rotate(ps->a);
	write(1, "rra\n", 4);
}

void	rrb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	reverse_rotate(ps->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	rra(ps);
	rrb(ps);
	write(1, "rrr\n", 4);
}
