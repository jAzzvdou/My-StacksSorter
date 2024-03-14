/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:42:55 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 15:42:57 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	verify_instruction(t_pushswap *ps, char *terminal)
{
	if (!ft_strncmp(terminal, "sa\n", 3))
		sa(ps);
	else if (!ft_strncmp(terminal, "sb\n", 3))
		sb(ps);
	else if (!ft_strncmp(terminal, "ss\n", 3))
		ss(ps);
	else if (!ft_strncmp(terminal, "pa\n", 3))
		pa(ps);
	else if (!ft_strncmp(terminal, "pb\n", 3))
		pb(ps);
	else if (!ft_strncmp(terminal, "ra\n", 3))
		ra(ps);
	else if (!ft_strncmp(terminal, "rb\n", 3))
		rb(ps);
	else if (!ft_strncmp(terminal, "rr\n", 3))
		rr(ps);
	else if (!ft_strncmp(terminal, "rra\n", 4))
		rra(ps);
	else if (!ft_strncmp(terminal, "rrb\n", 4))
		rrb(ps);
	else if (!ft_strncmp(terminal, "rrr\n", 4))
		rrr(ps);
	else
		write(2, "Error\n", 6);
}

void	reader(t_pushswap *ps)
{
	char	*terminal;

	terminal = get_next_line(STDIN_FILENO);
	while (terminal)
	{
		verify_instruction(ps, terminal);
		free(terminal);
		terminal = get_next_line(STDIN_FILENO);
	}
	free(terminal);
}
