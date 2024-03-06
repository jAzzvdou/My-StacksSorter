/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:17:47 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/05 23:43:18 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size >= 500)
		range = 35;
	else if (size >= 100)
		range = 12;
	return (range);
}
