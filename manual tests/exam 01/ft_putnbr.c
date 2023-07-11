#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int i)
{
	char	c;

	if (i < 10)
	{
		c = i + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}