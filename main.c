/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/05 11:42:22 by jazevedo         ###   ########.fr       */
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

//cost_of_way will calculate the cost of a way to sort the stack
int	cost_of_way(t_pushswap *ps, char *way)
{
	t_pushswap	*ps_copy;
	int		cost;

	ps_copy = (t_pushswap *)malloc(sizeof(t_pushswap));
	*ps_copy = *ps;
	cost = 0;
	while (way[cost])
	{
		if (way[cost] == 's')
			sa(ps_copy);
		else if (way[cost] == 'r')
			ra(ps_copy);
		else if (way[cost] == 'p')
			pb(ps_copy);
		else if (way[cost] == 'a')
			rra(ps_copy);
		cost++;
	}
	cost += stack_size(ps_copy->b);
	free(ps_copy);
	return (cost);
}

//min_cost will return the minimum cost of the costs array
int	min_cost(int *costs)
{
	int	min;
	int	i;

	min = costs[0];
	i = 1;
	while (i < 6)
	{
		if (costs[i] < min)
			min = costs[i];
		i++;
	}
	return (min);
}

//the second algorithm will calculate the cheapest way to sort the stack with 4 or 5 elements and it will calculate the cost of each way and choose the cheapest one
void	second_algorithm(t_pushswap *ps)
{
	int	*costs;
	int	i;

	costs = (int *)malloc(sizeof(int) * 6);
	costs[0] = cost_of_way(ps, "sa");
	costs[1] = cost_of_way(ps, "ra");
	costs[2] = cost_of_way(ps, "rra");
	costs[3] = cost_of_way(ps, "rra\nsa");
	costs[4] = cost_of_way(ps, "ra\nsa");
	costs[5] = cost_of_way(ps, "pb");
	i = 0;
	while (i < 6)
	{
		if (costs[i] == min_cost(costs))
			break ;
		i++;
	}
	if (i == 0)
		sa(ps);
	else if (i == 1)
		ra(ps);
	else if (i == 2)
		rra(ps);
	else if (i == 3)
	{
		rra(ps);
		sa(ps);
	}
	else if (i == 4)
	{
		ra(ps);
		sa(ps);
	}
	else if (i == 5)
		pb(ps);
	free(costs);
}

//free_everything will free the stack a and the stack b
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
		else if (stack_size(ps.a) == 4 || stack_size(ps.a) == 5)
			second_algorithm(&ps);
		else
			third_algorithm(&ps);
	}
	//function to free everything
	free_everything(&ps);
	return (0);
}

//PARA 3 ELEMENTOS: MÁXIMO DE 3 MOVIMENTOS -> 6 WAYS (UM BANDO DE IF)
//PARA 5 ELEMENTOS: MÁXIMO DE 12 MOVIMENTOS -> 120 WAYS (ALGORITMO BÁSICO)
//PARA 100 ELEMENTOS: MÁXIMO DE 700 MOVIMENTOS -> 100! WAYS (ALGORITMO AVANÇADO)
//PARA 500 ELEMENTOS: MÁXIMO DE 5500 MOVIMENTOS -> 500! WAYS (ALGORITMO AVANÇADO)
