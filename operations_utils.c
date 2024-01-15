/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:19:46 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/15 16:34:01 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	swap(t_stack **stack)
{
	t_stack	*second;

	// make sure there are at least 2 elements
	if (!*stack || !(*stack)->next)
		return (0);
	// save the second element because the next step will lose the pointer to it
	second = (*stack)->next;
	// first element points to the third element
	(*stack)->next = second->next;
	// second element points to the first element
	second->next = (*stack)->next;
	// second becomes the new head of the stack
	*stack = second;
	return (0);
}

int	push(t_stack **stack_from, t_stack **stack_to)
{
	(void)stack_from;
	(void)stack_to;
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	// make sure there are at least 2 elements
	if (!*stack || !(*stack)->next)
		return (0);
	// find the penultimate element
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	// save the last element because the next step will lose the pointer to it
	last = tmp->next;
	// penultimate element becomes the new last element, so it points to NULL
	tmp->next = NULL;
	// last element points to the first element
	last->next = *stack;
	// last element becomes the new head of the stack
	*stack = last;
	return (0);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*second;

	// make sure there are at least 2 elements
	if (!*stack || !(*stack)->next)
		return (0);
	// find the last element
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	// last element points to the first element
	tmp->next = *stack;
	// save the second element because the next step will lose the pointer to it
	second = (*stack)->next;
	// first element becomes the new last element, so it points to NULL
	(*stack)->next = NULL;
	// second element becomes the new head of the stack
	*stack = second;
	return (0);
}
