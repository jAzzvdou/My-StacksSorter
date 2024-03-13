/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:57:14 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 02:38:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *ps)
{
	if (!ps->b || !ps->b->size)
		return ;
	push(ps->b, ps->a);
	write(1, "pa\n", 3);
}

void	pb(t_pushswap *ps)
{
	if (!ps->a || !ps->a->size)
		return ;
	push(ps->a, ps->b);
	write(1, "pb\n", 3);
}
