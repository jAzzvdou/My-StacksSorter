#include "push_swap.h"

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size >= 500)
		range = 50;
	else if (size >= 100)
		range = 12;
	return (range);
}
