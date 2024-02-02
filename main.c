/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/02 16:17:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algorithm(t_pushswap *ps)
{
	//1 3 2
	if (ps->a->value < ps->a->next->value
		&& ps->a->value < ps->a->next->next->value
		&& ps->a->next->value > ps->a->next->next->value)
	{
		sa(ps);
		ra(ps);
	}
	//2 1 3
	else if (ps->a->value > ps->a->next->value
		&& ps->a->value < ps->a->next->next->value
		&& ps->a->next->value < ps->a->next->next->value)
		sa(ps);
	//2 3 1
	else if (ps->a->value < ps->a->next->value
		&& ps->a->value > ps->a->next->next->value
		&& ps->a->next->value > ps->a->next->next->value)
		rra(ps);
	//3 1 2
	else if (ps->a->value > ps->a->next->value
		&& ps->a->value > ps->a->next->next->value
		&& ps->a->next->value < ps->a->next->next->value)
		ra(ps);
	//3 2 1
	else if (ps->a->value > ps->a->next->value
		&& ps->a->value > ps->a->next->next->value
		&& ps->a->next->value > ps->a->next->next->value)
	{
		sa(ps);
		rra(ps);
	}
}

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	int	i;

        if (argc == 1 || (argc == 2 && !argv[1][0]))
                return (write(2, "\n", 1));
        if (argc == 2)
	{
                argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i])
			i++;
		argc = i;
	}
	else
	{
		argc--;
		argv++;
	}
        if (!verify_argv(argv))
                return (write(2, "Error\n", 6));
        if (!is_int(argv))
                return (write(2, "Error\n", 6));
        if (is_duplicated(argv))
                return (write(2, "Error\n", 6));
        if (!in_stack(ps, argc, argv))
                return (1);
	return (0);
}
	

int	main(int argc, char **argv)
{
	t_pushswap	ps = {0};

	if (invalid_arguments(&ps, argc, argv))
		return (1);
	while (!is_sorted(ps.a) || ps.b)
	{
		if (stack_size(ps.a) == 2)
		{
			if (ps.a->value > ps.a->next->value)
				sa(&ps);
			break ;
		}
		else if (stack_size(ps.a) == 3)
			first_algorithm(&ps);	
	}
	return (0);
}

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
