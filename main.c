/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/16 17:23:09 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = {0};
	if (start_pushswap(&pushswap, argc, argv))
		return (1);
	debugger(&pushswap);
	while (!is_sorted(pushswap.a) || pushswap.b)
	{
		// Here we will do the sorting algorithm
	}
	return (0);
}
