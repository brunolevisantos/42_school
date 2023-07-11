#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

unsigned int	product(unsigned int a, unsigned int b)
{
	unsigned int	i;

	i = 1;
	while (i < 100)
	{
		// printf("a multipplicar %u por %u\n", a, i);
		if ((a * i) == b)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

	i = 1;
	if (a < 1 || b < 1)
		return (0);
	while (i < 100)
	{
		if (product(a, i * b))
			return (i * b);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("resultado e: %u\n", lcm(-1, 2932));
// }