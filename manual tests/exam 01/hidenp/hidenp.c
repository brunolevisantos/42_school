#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	found(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (!s2[j])
			return (0);
		i++;
	}
	if (!s1[i])
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (found(av[1], av[2]) || !av[1])
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write (1, "\n", 1);
	return (0);
}