#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(long int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr % 10);
		ft_putnbr(nbr / 10);
	}
}
