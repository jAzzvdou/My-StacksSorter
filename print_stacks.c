/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:03 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/15 17:04:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	print_stacks(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
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
