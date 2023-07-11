#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*wrd;

	i = 0;
	j = 0;
	// wrd = 0;
	if (ac >= 2)
	{
		while (av[1][i] == ' ')
			i++;
		while (av[1][i] && av[1][i] != ' '/* (av[1][i] >= 'a' && av[1][i] >= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z') */)
			wrd[j++] = av[1][i++];
		wrd[j] = 0;
		while (av[1][i] == ' ')
			i++;
		while (av[1][i])
		{
			while (av[1][i] == ' ')
				i++;
			while (av[1][i] && av[1][i] != ' ')
			{
				write (1, &av[1][i], 1);
				i++;
			}
			write (1, " ", 1);
		}
		j = 0;
		while (wrd[j])
			write (1, &wrd[j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}