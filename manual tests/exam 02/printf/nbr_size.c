#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	nbr_size(int nbr)
{
	int	i;

	i = 1;
	while (nbr / 10 > 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
