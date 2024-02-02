/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:19:46 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/02 16:19:41 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack)->next;
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

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	second = (*stack)->next;
	(*stack)->next = NULL;
	*stack = second;
	return (0);
}
