#include "push_swap.h"

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_atoi(const char *nptr)
{
	int	nb;
	int	mult;

	nb = 0;
	mult = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		mult = -mult;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return (nb * mult);
}

long	my_atol(const char *nptr)
{
	long	nb;
	int		mult;

	nb = 0;
	mult = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		mult = -mult;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return (nb * mult);
}

void	my_bzero(void *s, size_t n)
{
	char	*zero_s;

	zero_s = s;
	while (n--)
		zero_s[n] = 0;
}

void	*my_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = nmemb * size;
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	my_bzero(ptr, i);
	return (ptr);
}
