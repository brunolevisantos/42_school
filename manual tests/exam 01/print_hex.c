#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str);
void	ft_putchar(char c);
int	ft_strlen(char	*str);
void run(int	nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr <= ft_strlen(base))
		ft_putchar(base[nbr]);
	else
	{
		run(nbr / ft_strlen(base));
		run(nbr % ft_strlen(base));
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		nbr;

	i = 0;
	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		run(nbr);
	}
	write (1, "\n", 1);
	return (0);
}