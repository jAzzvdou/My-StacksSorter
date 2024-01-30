/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/30 20:11:08 by jazevedo         ###   ########.fr       */
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
			return (write(2, "Error\n", 6), 0);
	return (1);
}

int	no_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i++])
		//verificar se cada argumento está na escala do INT
		if (argv //não for um INT)
			 return (0);
	return (1);
}


int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write(2, "\n", 1));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!verify_argv(argc, argv));
		return (1);
	if (!no_int(argv))
		return (write(2, "Error\n", 6));
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
