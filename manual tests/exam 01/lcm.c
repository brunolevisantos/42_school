#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int	n;

	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

int		main(int argc, char **argv)
{
	unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[2]);
	printf("%d\n", lcm(a,b));
}