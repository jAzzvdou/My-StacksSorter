/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:49:11 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 09:50:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     push_new(t_stack **stack, long value)
{
        t_stack *new;

        new = malloc(sizeof(t_stack));
        if (!new)
                return (0);
        new->value = value;
        new->next = *stack;
        *stack = new;
        return (1);
}

int     in_stack(t_pushswap *pushswap, int argc, char **argv)
{
        long    value;

        while (--argc > 0)
        {
                value = ft_atoi(argv[argc]);
                if (!push_new(&pushswap->a, value))
                        return (0);
        }
        value = ft_atoi(argv[--argc]);
        return (1);
}

int     is_sorted(t_stack *stack)
{
        if (!stack)
                return (1);
        while (stack->next)
        {
                if (stack->value > stack->next->value)
                        return (0);
                stack = stack->next;
        }
        return (1);
}

int     stack_size(t_stack *stack)
{
        int     i;

        i = 0;
        while (stack)
        {
                stack = stack->next;
                i++;
        }
        return (i);
}