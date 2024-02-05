/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:59:49 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/05 14:47:57 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_pushswap *ps)
{
	rotate(&ps->a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_pushswap *ps)
{
	rotate(&ps->b);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_pushswap *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	write(1, "rr\n", 3);
	return (0);
}
