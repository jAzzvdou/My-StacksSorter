/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/06 15:40:09 by jazevedo         ###   ########.fr       */
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

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = argvs_size(argv);
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
	t_pushswap	ps;

	ps = (t_pushswap){0};
	if (invalid_arguments(&ps, argc, argv))
		return (1);
	print_stacks(&ps);
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
		else if (stack_size(ps.a) <= 5)
			second_algorithm(&ps);
		//else
		//	third_algorithm(&ps);
	}
	print_stacks(&ps);
	free_everything(&ps);
	return (0);
}
