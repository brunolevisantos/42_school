#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	repeated(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	exists(char *str, char c)
{
	int	i;
	int	r;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (exists(av[2], av[1][i]))
				if (!repeated(av[1], av[1][i], i))
					write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}