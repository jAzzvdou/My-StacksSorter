/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:43:53 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/18 11:39:18 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
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
	set_index(ps->a->top, bubblesort(array, size), size);
	free(array);
}
