/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 16:35:36 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(t_pushswap *ps)
{
	t_node	*tmp;

	while (ps->a->top)
	{
		tmp = ps->a->top;
		ps->a->top = ps->a->top->prev;
		free(tmp);
	}
	while (ps->b->top)
	{
		tmp = ps->b->top;
		ps->b->top = ps->b->top->prev;
		free(tmp);
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

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	if (argc <= 2)
		return (1);
	argv++;
	if (!verify_argv(argv))
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	if (is_duplicated(argv))
		return (write(2, "Error\n", 6));
	put_in_stack(ps, argc, argv);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->prev)
	{
		if (tmp->value > tmp->prev->value)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	ps = (t_pushswap){0};
	if (invalid_arguments(&ps, argc, argv))
		return (1);

	if (!is_sorted(ps.a) || ps.b->size)
	{
		if (ps.a->size == 2 && ps.a->top->value > ps.a->top->prev->value)
			sa(&ps);
		else if (ps.a->size == 3)
			first_algorithm(&ps);
		else if (ps.a->size <= 5)
			second_algorithm(&ps);
		else
			t(&ps);
	}
	if (is_sorted(ps.a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_everything(&ps);
	return (0);
}
