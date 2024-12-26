#include "push_swap_bonus.h"

void	sa(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	swap(ps->a);
}

void	sb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	swap(ps->b);
}

void	ss(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	sa(ps);
	sb(ps);
}
