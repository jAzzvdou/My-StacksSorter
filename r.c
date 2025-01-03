#include "push_swap.h"

void	ra(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	rotate(ps->a);
	write(1, "ra\n", 3);
}

void	rb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	rotate(ps->b);
	write(1, "rb\n", 3);
}

void	rr(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	ra(ps);
	rb(ps);
	write(1, "rr\n", 3);
}
