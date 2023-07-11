#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		j = i;
		if (av[1][j - 1] == ' ')
		{
			j--;
			while (av[1][j] == ' ')
				j--;
		}
		while (av[1][j] != ' ')
			j--;
		while (av[1][j])
		{
			if(av[1][j] != ' ')
				write(1, &av[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}