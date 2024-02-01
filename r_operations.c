/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:59:49 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 10:00:18 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ra(t_data *data)
{
        rotate(&data->stack_a);
	write(1, "ra\n", 3);
        return (0);
}

int     rb(t_data *data)
{
        rotate(&data->stack_b);
	write(1, "rb\n", 3);
        return (0);
}

int     rr(t_data *data)
{
        rotate(&data->stack_a);
        rotate(&data->stack_b);
	write(1, "rr\n", 3);
        return (0);
}
