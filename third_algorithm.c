/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:02 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/09 17:27:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int	i;
	int	*array;
	int	size;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	*bubblesort(int *stack, int size)
{
        int     i;
        int     ii;
        int     tmp;

        i = -1;
        while (++i < size)
        {
                ii = i;
                while (++ii < size)
                {
                        if (stack[i] > stack[ii])
                        {
                                tmp = stack[i];
                                stack[i] = stack[ii];
                                stack[ii] = tmp;
                        }
                }
        }
	return (stack);
}

void    set_index(t_stack *stack, int *array, int size)
{
        int     i;

        while (stack)
        {
                i = -1;
                while (++i < size)
                {
                        if (stack->value == array[i])
                                stack->index = i;
                }
                stack = stack->next;
        }
}

int	cost_to_top(t_stack *stack, int index)
{
	int	i;
	int	size;
	
	size = stack_size(stack);
	i = 0;
	while (stack)
	{
		if (stack->index == index)
		{
			if (i < size / 2)
				return (i);
			else
				return (-(size - i));
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int	cheapest_in_range(t_pushswap *ps, int range)
{
	int	i;
	int	cost;
	int	tmp;
	int	smallest;

	smallest = 2147483647;
	cost = 0;
	i = -1;
        while (++i < range)
        {
                tmp = cost_to_top(ps->a, i);
                if (tmp < 0)
                {
                        if (-tmp < smallest)
                        {
                                smallest = -tmp;
                                cost = tmp;
                        }
                }
                else if (tmp < smallest)
                {
                        smallest = tmp;
                        cost = tmp;
                }
        }
	return (cost);
}

void	make_moves(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rra(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			ra(ps);
	}
	pb(ps);
}

void	third_algorithm(t_pushswap *ps, int range)
{
	int	size;
	int	cost;
	int	backup;
	int	*array;

	backup = range;
	while (ps->a)
	{
		size = stack_size(ps->a); //Passa todo o conteúdo da stack A para um array.
		array = bubblesort(stack_to_array(ps->a), size); //Organiza esse array em ordem crescente.
		set_index(ps->a, array, size); //Seta os valores da stack A por index. O menor número é index zero e o maior é index N.
		cost = cheapest_in_range(ps, range); //Mostra o custo para mandar um número do RANGE para a stack B com menos movimentos.
						//RANGE são os X´s menores números da Stack A.
		make_moves(ps, cost); //Manda o número com o menor custo que está dentro do RANGE para a Stack B.
		range--;
		if (!range)
			range = backup;
	}
	while (ps->b)
	{
		pa(ps);
		pa(ps);
		if (ps->a->value > ps->a->next->value)
			sa(ps);
		//IMPLEMENTAR ORGANIZAÇÃO PARA RANGE != 2.
	} //SÓ ESTÁ FUNCIONANDO COM RANGE = 2 POR ENQUANTO.
}
