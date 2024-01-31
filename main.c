/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/31 00:19:32 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

int	only_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i++])
		if (!is_number(s[i]))
			return (0);
	return (1);
}

int	verify_argv(int argc, char **argv)
{
	while (--argc > 1)
		if (!only_number(argv[argc]))
			return (0);
	return (1);
}

int	is_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i++])
	{
		if (strlen(argv[i] > 11 || ft_atol(argv[i]) > 2147483647
			|| ft_atol(argv[i]) < -2147483648)
			return (0);
	}
	return (1);
}


int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write(2, "\n", 1));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!verify_argv(argc, argv));
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	
	return (0);
}

////////////////////////////////////////////////////////////////////////////////

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

//SE FOR CARACTERES NÃO NUMÉRICOS: Error\n ---------- CHECK
//SE FOR ACIMA DO MAXINT: Error\n ---------- CHECK
//SE FOR ABAIXO DO MININT: Error\n ---------- CHECK
//SE FOREM NÚMEROS DUPLICADOS: Error\n
//SE FOR SÓ ./push_swap: \n ---------- CHECK
//SE OS NÚMEROS JÁ ESTIVEREM ORDENADOS: \n

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
