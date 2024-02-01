/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 18:09:23 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algorithm(t_pushswap *pushswap)
{
	if (pushswap->a->value == 1 && pushswap->a->next->value == 3)
	{
		sa(pushswap);  // 1 3 2 -> 3 1 2
		ra(pushswap);  // 3 1 2 -> 1 2 3
	}	
	else if (pushswap->a->value == 2 && pushswap->a->next->value == 1)
		sa(pushswap);  // 2 1 3 -> 1 2 3
	else if (pushswap->a->value == 2 && pushswap->a->next->value == 3)
		rra(pushswap); // 2 3 1 -> 1 2 3
	else if (pushswap->a->value == 3 && pushswap->a->next->value == 1)
		ra(pushswap);  // 3 1 2 -> 1 2 3
	else if (pushswap->a->value == 3 && pushswap->a->next->value == 2)
	{
		sa(pushswap);  // 3 2 1 -> 2 3 1
		rra(pushswap); // 2 3 1 -> 1 2 3
	}
}

int	invalid_arguments(int argc, char **argv)
{
	t_pushswap	pushswap = {0};

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
	return (0);
}
	

int	main(int argc, char **argv)
{
	t_pushswap	pushswap = {0};

	if (invalid_arguments(argc, argv))
		return (1);
	while (!is_sorted(pushswap.a) || pushswap.b)
	{
		if (stack_size(pushswap.a) == 2)
		{
			if (pushswap.a->value > pushswap.a->next->value)
				sa(&pushswap);
			break ;
		}
		else if (stack_size(pushswap.a) == 3)
			first_algorithm(&pushswap);	
	}
	return (0);
}

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
