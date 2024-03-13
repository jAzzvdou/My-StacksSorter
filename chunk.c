/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:40:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 16:21:48 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size < 11)
		range = 5;
	else if (size < 151)
		range = 8;
	else if (size > 150)
		range = 18;
	return (range);
}

void	set_chunk(int *start, int *end, int size)
{
	int	chunk;

	chunk = size / set_range(size);
	*start = (size / 2) - chunk;
	*end = (size / 2) + chunk;
	if (*end >= (size - 3))
		*end = size - 4;
}
