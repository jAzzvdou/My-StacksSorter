/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:55:14 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 09:56:13 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     sa(t_data *data)
{
        swap(&data->stack_a);
        write(1, "sa\n", 3);
        return (0);
}

int     sb(t_data *data)
{
        swap(&data->stack_b);
	write(1, "sb\n", 3);
        return (0);
}

int     ss(t_data *data)
{
        swap(&data->stack_a);
        swap(&data->stack_b);
	write(1, "ss\n", 3);
        return (0);
}
