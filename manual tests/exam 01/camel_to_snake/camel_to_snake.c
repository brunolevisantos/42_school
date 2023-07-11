#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write (1, &str[i], 1);
}

char	*new_str(char *old)
{
	int		i;
	int		s;
	char	*new;

	i = 0;
	s = 0;
	while (old[i])
	{
		if (old[i] >= 'A' && old[i] <= 'Z')
			s++;
		i++;
	}
	new = malloc(sizeof(char) * (i + s + 1));
	i = 0;
	s = 0;
	while (old[i])
	{
		if (old[i] >= 'A' && old[i] <= 'Z')
		{
			old[i] += 32;
			new[s] = '_';
			s++;
		}
		new[s++] = old[i++];
	}
	new[s] = 0;
	return (new);
}

int	main(int ac, char **av)
{
	int		i;
	char	*new;

	i = 0;
	if (ac == 2)
	{
		new = new_str(av[1]);
		ft_putstr(new);
	}
	write (1, "\n", 1);
	return (0);
}