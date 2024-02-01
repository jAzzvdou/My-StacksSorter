/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:57:14 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 09:58:57 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     pa(t_data *data)
{
        push(&data->stack_b, &data->stack_a);
	write(1, "pa\n", 3);
        return (0);
}

int     pb(t_data *data)
{
        push(&data->stack_a, &data->stack_b);
	write(1, "pb\n", 3);
        return (0);
}
