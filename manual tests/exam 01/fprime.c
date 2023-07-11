#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	is_prime(int test)
{
	int	i;

	i = 2;
	if (test == 0 || test == 1)
		return (0);
	while (i < test)
	{
		if (test % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int	main(int ac, char **av)
{
	int	i;
	int	first;
	int	nbr;

	i = 2;
	first = 1;
	if (ac == 2)
	{
		nbr = atoi(av[1]);
		if (nbr == 1)
			write(1, "1", 1);
		while (i <= nbr)
		{
			if (nbr % i == 0 && is_prime(i))
			{
				nbr = nbr / i;
				if (first)
					printf("%d", i);
				else
					printf("*%d", i);
				first = 0;
			}
			else
				i++;
		}	
	}
	printf("\n");
	return (0);
}