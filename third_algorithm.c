/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:57:38 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/07 10:18:24 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_algorithm(t_pushswap *ps)
{
	int	i;
	int	position[2];

	pb(ps);
	pb(ps);
	while (stack_size(ps->a) > 3)
	{
		position[0] = find_smallest(ps->a);
		i = -1;
		while (++i < position[0])
			ps->a = ps->a->next;
		postion[1] =  ?
}
