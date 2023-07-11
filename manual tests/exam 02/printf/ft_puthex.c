#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	nbr_size(int nbr);

void	ft_puthex(int nbr)
{
	char	*base = "0123456789abcdef";
	int		i;

	i = nbr_size(nbr);
	if (i < 16)
		write (1, &base[i], 1);
	else
	{
		ft_puthex(nbr % 10);
		ft_puthex(nbr / 10);
	}
}