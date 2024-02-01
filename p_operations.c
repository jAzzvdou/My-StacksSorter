/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:57:14 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 11:35:06 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     pa(t_pushswap *ps)
{
        push(&ps->b, &ps->a);
	write(1, "pa\n", 3);
        return (0);
}

int     pb(t_pushswap *ps)
{
        push(&ps->a, &ps->b);
	write(1, "pb\n", 3);
        return (0);
}
