/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:00:36 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 11:37:12 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     rra(t_pushswap *ps)
{
        reverse_rotate(&ps->a);
	write(1, "rra\n", 4);
        return (0);
}

int     rrb(t_pushswap *ps)
{
        reverse_rotate(&ps->b);
	write(1, "rrb\n", 4);
        return (0);
}

int     rrr(t_pushswap *ps)
{
        reverse_rotate(&ps->a);
        reverse_rotate(&ps->b);
	write(1, "rrr\n", 4);
        return (0);
}
