/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:03 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 11:39:20 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	print_stacks(t_pushswap *ps)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ps->a;
	stack_b = ps->b;
	while (stack_a || stack_b)
	{
		if (stack_a) 
		{
			printf("%11d", stack_a->value);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("%11d", stack_b->value);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	return (0);
}
