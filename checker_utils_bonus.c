#include "push_swap_bonus.h"

void	verify_instruction(t_pushswap *ps, char *terminal)
{
	if (!my_strncmp(terminal, "sa\n", 3))
		sa(ps);
	else if (!my_strncmp(terminal, "sb\n", 3))
		sb(ps);
	else if (!my_strncmp(terminal, "ss\n", 3))
		ss(ps);
	else if (!my_strncmp(terminal, "pa\n", 3))
		pa(ps);
	else if (!my_strncmp(terminal, "pb\n", 3))
		pb(ps);
	else if (!my_strncmp(terminal, "ra\n", 3))
		ra(ps);
	else if (!my_strncmp(terminal, "rb\n", 3))
		rb(ps);
	else if (!my_strncmp(terminal, "rr\n", 3))
		rr(ps);
	else if (!my_strncmp(terminal, "rra\n", 4))
		rra(ps);
	else if (!my_strncmp(terminal, "rrb\n", 4))
		rrb(ps);
	else if (!my_strncmp(terminal, "rrr\n", 4))
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
