#include "push_swap_bonus.h"

int	is_number(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

int	only_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
		if (!is_number(s[i++]))
			return (0);
	return (1);
}

int	verify_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (!only_number(argv[i]))
			return (0);
	return (1);
}

int	is_int(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (my_strlen(argv[i]) > 11 || my_atol(argv[i]) > 2147483647
			|| my_atol(argv[i]) < -2147483648)
			return (0);
	}
	return (1);
}

int	is_duplicated(char **argv)
{
	int	i;
	int	ii;

	i = -1;
	while (argv[++i])
	{
		ii = i;
		while (argv[++ii])
			if (my_atoi(argv[i]) == my_atoi(argv[ii]))
				return (1);
	}
	return (0);
}
