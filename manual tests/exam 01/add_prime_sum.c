#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str);
void ft_putnbr(int i);

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

int main(int ac, char **av)
{
	int	i;
	int	nbr;
	int	res;

	i = 2;
	res = 0;
	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		if (nbr < 1)
			write (1, "0", 1);
		else
		{
			res = nbr;
			while (i < nbr)
			{
				if (is_prime(i))
					res += i;
				i++;
			}
		}
		ft_putnbr(res);
	}
	else
		write (1, "0", 1);
	write (1, "\n", 1);
	return (0);
}