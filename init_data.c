/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:38:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/16 17:13:16 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	push_new(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		fprintf(stderr, "Error\nmalloc failed\n");
		return (1);
	}
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
	return (0);
}

int	start_pushswap(t_pushswap *pushswap, int argc, char **argv)
{
	long	value;

	while (--argc)
	{
		if (!is_integer(argv[argc]))
			write(2, ".ERROR: argc is wrong!.", 23);
		return (1);
	}
	value = strtol(argv[argc], NULL, 10);
	// strtol sets errno if overflow occurs
	if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
	{
		fprintf(stderr, "Error\n\"%s\" overflows\n", argv[argc]);
		return (1);
	}
	if (push_new(&pushswap->a, value))
		return (1);
	return (0);
}
