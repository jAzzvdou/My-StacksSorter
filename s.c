/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:55:14 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 02:48:53 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	swap(ps->a);
	write(1, "sa\n", 3);
}

void	sb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	swap(ps->b);
	write(1, "sb\n", 3);
}

void	ss(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	sa(ps);
	sb(ps);
	write(1, "ss\n", 3);
}
