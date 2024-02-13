/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/09 17:26:58 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(t_pushswap *ps)
{
	t_stack	*temp;

	while (ps->a)
	{
		temp = ps->a;
		ps->a = ps->a->next;
		free(temp);
	}
	while (ps->b)
	{
		temp = ps->b;
		ps->b = ps->b->next;
		free(temp);
	}
}

int	argvs_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	set_range(int size)
{
	int	range;

	range = 2;
	if (size >= 500)
		range = 25;
	else if (size >= 100)
		range = 5;
	return (range);
}

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	if (argc <= 2)
		return (1);
	argc--;
	argv++;
	if (!verify_argv(argv))
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	if (is_duplicated(argv))
		return (write(2, "Error\n", 6));
	if (!in_stack(ps, argc--, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;
	int		size;
	int		range;

	ps = (t_pushswap){0};	
	if (invalid_arguments(&ps, argc, argv))
		return (1);
	size = stack_size(ps.a);
	range = set_range(size);
	print_stacks(&ps);
	write(1, "\n", 1);
	if (!is_sorted(ps.a) || ps.b)
	{
		if (size == 2)
		{
			if (ps.a->value > ps.a->next->value)
				sa(&ps);
		}
		else if (size == 3)
			first_algorithm(&ps);
		else if (size <= 5)
			second_algorithm(&ps);
		else
			third_algorithm(&ps, range);
	}
	write(1, "\n", 1);
	print_stacks(&ps);
	free_everything(&ps);
	return (0);
}
