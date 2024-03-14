/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:42:16 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 12:42:32 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *stack1, t_stack *stack2)
{
	insert_node(pop(stack1), stack2);
}

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
