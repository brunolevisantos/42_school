#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	putnbr(int i)
{
	char	c;

	if (i < 10)
	{
		c = i + 48;
		write (1, &c, 1);
	}
	else
	{
		putnbr(i / 10);
		putnbr(i % 10);
	}
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 5 == 0 && i % 3 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
			putnbr(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}