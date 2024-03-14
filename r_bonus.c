/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:43:37 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 15:43:39 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	rotate(ps->a);
}

void	rb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	rotate(ps->b);
}

void	rr(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	ra(ps);
	rb(ps);
}
