/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:19:46 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 09:41:24 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bot = node;
		stack->size = 1;
		return ;
	}
	stack->top->next = node;
	node->prev = stack->top;
	node->next = NULL;
	stack->top = stack->top->next;
	stack->size = stack->size + 1;
}

t_node	*pop(t_stack *stack)
{
	t_node	*popnode;

	if (!stack || (!stack->top && !stack->bot))
		return (NULL);
	if (stack->top == stack->bot)
	{
		popnode = stack->top;
		stack->top = NULL;
		stack->bot = NULL;
		stack->size = stack->size - 1;
		return (popnode);
	}
	popnode = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	popnode->prev = NULL;
	stack->size = stack->size - 1;
	return (popnode);
}

void	swap(t_stack *stack)
{
	t_node	*topnode;
	t_node	*prevnode;

	if (stack->top == stack->bot)
		return ;
	topnode = pop(stack);
	prevnode = pop(stack);
	insert_node(topnode, stack);
	insert_node(prevnode, stack);
}

void	rotate(t_stack *stack)
{
	t_node	*popped;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		swap(stack);
		return ;
	}
	popped = pop(stack);
	stack->bot->prev = popped;
	popped->next = stack->bot;
	popped->prev = NULL;
	stack->bot = popped;
	stack->size = stack->size + 1;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*botnode;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		swap(stack);
		return ;
	}
	botnode = stack->bot;
	stack->bot = stack->bot->next;
	stack->bot->prev = NULL;
	botnode->next = NULL;
	botnode->prev = NULL;
	stack->size = stack->size - 1;
	insert_node(botnode, stack);
}
