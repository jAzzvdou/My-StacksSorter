/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/31 14:58:19 by jazevedo         ###   ########.fr       */
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
		if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) > 2147483647
			|| ft_atol(argv[i]) < -2147483648)
			return (0);
	}
	return (1);
}

int	is_duplicated(char **argv)
{
	int	i;
	int	ii;

	i = 0;
	while (argv[i++])
	{
		ii = i;
		while (argv[ii++])
			if (ft_atoi(argv[i]) == ft_atoi(argv[ii]))
				return (1);
	}
	return (0);
}

int	push_new(t_stack **stack, long value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->next = *stack;
	*stack = new;
	return (1);
}

int	in_stack(t_pushswap *pushswap, int argc, char **argv)
{
	long	value;

	value = ft_atoi(argv[--argc]);
	if (!push_new(&pushswap->a, value))
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = {0};
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write(2, "\n", 1));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!verify_argv(argc, argv));
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
		if (stack_size(pushswap.a) == 3)
			first_algorithm(&pushswap);
		// if stack have 5 elements = second algorithm
		// the second algorithm max moves is 12
		if (stack_size(pushswap.a) == 5)
			second_algorithm(&pushswap);
		// if stack have more than 5 elements = third algorithm
		// the third algorithm max moves is 700
		if (stack_size(pushswap.a) > 5)
			third_algorithm(&pushswap);
	}	
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
//SE FOREM NÚMEROS DUPLICADOS: Error\n ---------- CHECK
//SE FOR SÓ ./push_swap: \n ---------- CHECK
//SE OS NÚMEROS JÁ ESTIVEREM ORDENADOS: \n ---------- CHECK

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
