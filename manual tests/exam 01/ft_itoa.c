#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	get_len(int	nbr)
{
	int	len;

	len = 2;
	while (nbr / 10 > 10)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 1;
	res = 0;
	if (nbr > 10)
		len = get_len(nbr);
	res = malloc(sizeof(char) * len + 1);
	res[len] = 0;
	len--;
	while (nbr > 10)
	{
		res[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	res[len] = nbr + 48;
	return (res);
}

int	main(void)
{
	printf("resultado e %s\n", ft_itoa(15567));
}