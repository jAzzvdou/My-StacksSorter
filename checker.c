/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:06:00 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 08:57:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(t_pushswap *ps)
{
	t_stack	*temp;

	while (ps->a)
	{
		temp = ps->a;
		ps->a = ps->a->next;
		free(temp);
	}
	while (ps->b)
	{
		temp = ps->b;
		ps->b = ps->b->next;
		free(temp);
	}
}

int	argvs_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	if (argc <= 2)
		return (1);
	argc--;
	argv++;
	if (!verify_argv(argv))
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	if (is_duplicated(argv))
		return (write(2, "Error\n", 6));
	if (!in_stack(ps, argc--, argv))
		return (1);
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	ps = (t_pushswap){0};
	if (invalid_arguments(&ps, argc, argv))
		return (1);
	reader(&ps);
	if (is_sorted(ps.a) && !ps.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_everything(&ps);
	return (0);
}
