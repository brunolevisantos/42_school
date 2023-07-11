#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write (1, &str[i], 1);
	return (i);
}