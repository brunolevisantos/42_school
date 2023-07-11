#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int n;
	int	a;
	int	b;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		n = a;
		while (n > 0)
		{
			if (a % n == 0 && b % n == 0)
			{
				printf("%d", n);
				return (0);
			}
			n--;
		}
	}
	write (1, "\n", 1);
	return (0);
}