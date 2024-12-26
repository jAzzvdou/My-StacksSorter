#include "push_swap.h"

void	push(t_stack *stack1, t_stack *stack2)
{
	insert_node(pop(stack1), stack2);
}

void	pa(t_pushswap *ps)
{
	if (!ps->b || !ps->b->size)
		return ;
	push(ps->b, ps->a);
	write(1, "pa\n", 3);
}

void	pb(t_pushswap *ps)
{
	if (!ps->a || !ps->a->size)
		return ;
	push(ps->a, ps->b);
	write(1, "pb\n", 3);
}
