/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/04 13:18:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_range_info	*start_range(t_pushswap *ps, int size)
{
	int				i;
	int				ii;
	t_range_info	*r;

	r = malloc(sizeof(t_range_info));
	ps->start = ((size / 2)) - ps->range;
	ps->end = ((size / 2) + (size % 2)) + (ps->range - 1);
	r->size = ps->end - ps->start + 1;
	r->index_arr = malloc(sizeof(int) * r->size);
	ii = ps->start;
	i = 0;
	while (i <= ps->end - ps->start)
		r->index_arr[i++] = ii++;
	return (r);
}

void	remove_from_range(t_pushswap *ps)
{
	int	i;
	int	ii;
	int	*new_r;

	new_r = malloc(sizeof(int) * (ps->r->size - 1));
	ii = 0;
	i = 0;
	while (i < ps->r->size)
	{
		if (ps->a && ps->r->index_arr[i] == ps->a->index)
			i++;
		else
			new_r[ii++] = ps->r->index_arr[i++];
	}
	free(ps->r->index_arr);
	ps->r->index_arr = new_r;
}

int	range_size(t_pushswap *ps, t_range_info *new_r)
{
	int	i;
	int	ii;

	i = new_r->start;
	ii = ps->start;
	while (i < ii)
		i++;
	i -= new_r->start;
	ii = ps->end;
	while (ii <= new_r->end)
		ii++;
	ii -= ps->end;
	return (i + ii - 1);
}

void	substitution(t_pushswap *ps, t_range_info *new_r, int *sorted_arr)
{
	int	i;
	int	ii;
	int	iii;

	i = 0;
	ii = new_r->start - 1;
	iii = ps->start;
	while (ii < iii - 1)
		new_r->index_arr[i++] = sorted_arr[ii++];
	ii = ps->end;
	iii = new_r->end;
	while (ii < iii)
		new_r->index_arr[i++] = sorted_arr[ii++];
	ps->start = new_r->start;
	ps->end = new_r->end;
}

t_range_info	*next_range(t_pushswap *ps, int *sorted_arr, int size)
{
	t_range_info	*new_r;

	new_r = malloc(sizeof(t_range_info));
	new_r->start = ps->start - ps->range;
	if (new_r->start < 0)
		new_r->start = 0;
	new_r->end = ps->end + ps->range;
	if (new_r->end > size - 1)
		new_r->end = size - 1;
	new_r->size = range_size(ps, new_r);
	new_r->index_arr = malloc(sizeof(int) * new_r->size);
	substitution(ps, new_r, sorted_arr);
	return (new_r);
}
