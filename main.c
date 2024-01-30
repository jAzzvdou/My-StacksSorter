/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/30 16:49:08 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write(2, "\n", 1));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');


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

//SE FOR CARACTERES NÃO NUMÉRICOS: Error\n
//SE FOR ACIMA DO MAXINT: Error\n
//SE FOR ABAIXO DO MININT: Error\n
//SE FOREM NÚMEROS DUPLICADOS: Error\n
//SE FOR SÓ ./push_swap: \n
//SE OS NÚMEROS JÁ ESTIVEREM ORDENADOS: \n

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
