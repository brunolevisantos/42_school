#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

// int main(void)
// {
// 	printf("resultado %d\n", ft_atoi("    -123"));
// }