/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:49:11 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/13 13:17:32 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argv_to_array(char **argv, int size)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

int	*bubblesort(int *array, int size)
{
	int	i;
	int	ii;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		ii = i;
		while (++ii < size)
		{
			if (array[i] > array[ii])
			{
				tmp = array[i];
				array[i] = array[ii];
				array[ii] = tmp;
			}
		}
	}
	return (array);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack(int *array, int size)
{
	int	i;
	t_stack	*stack;
	t_node	*node;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = size;
	while (i--)
	{
		node = new_node(array[i]);
		insert_node(node, stack);
	}
	return (stack);
}

void	put_in_stack(t_pushswap *ps, int argc, char **argv)
{
	int	size;
	int	*array;

	size = argc - 1;
	array = argv_to_array(argv, size);
	ps->a = create_stack(array, size);
	ps->b = init_stack();
	ps->sorted = bubblesort(array, size);
}
