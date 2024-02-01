/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 09:51:15 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algorithm(t_pushswap *pushswap)
{
	if (pushswap->a->value > pushswap->a->next->value
		&& pushswap->a->value < pushswap->a->next->next->value)
		sa(pushswap);
	else if (pushswap->a->value > pushswap->a->next->value
		&& pushswap->a->value > pushswap->a->next->next->value)
	{
		sa(pushswap);
		rra(pushswap);
	}
	else if (pushswap->a->value < pushswap->a->next->value
		&& pushswap->a->value > pushswap->a->next->next->value)
		ra(pushswap);
	else if (pushswap->a->value < pushswap->a->next->value
		&& pushswap->a->value < pushswap->a->next->next->value)
	{
		sa(pushswap);
		ra(pushswap);
	}
	else if (pushswap->a->value > pushswap->a->next->value
		&& pushswap->a->value < pushswap->a->next->next->value)
	{
		sa(pushswap);
		rra(pushswap);
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = {0};
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write(2, "\n", 1));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!verify_argv(argc, argv))
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	if (is_duplicated(argv))
		return (write(2, "Error\n", 6));
	if (!in_stack(&pushswap, argc, argv))
		return (1);
	while (!is_sorted(pushswap.a) || pushswap.b)
	{
		if (stack_size(pushswap.a) == 2)
		{
			if (pushswap.a->value > pushswap.a->next->value)
				sa(&pushswap);
			break ;
		}
		// if stack have only 3 elements = first algorithm
		// the first algotithm max moves is 3
		else if (stack_size(pushswap.a) == 3)
			first_algorithm(&pushswap);
		// if stack have 5 elements = second algorithm
		// the second algorithm max moves is 12
		/*
		else if (stack_size(pushswap.a) == 4
			|| stack_size(pushswap.a) == 5)
			second_algorithm(&pushswap);
		// if stack have more than 5 elements = third algorithm
		// the third algorithm max moves is 700
		else if (stack_size(pushswap.a) > 5)
			third_algorithm(&pushswap);
		*/
	}	
	return (0);
}

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
