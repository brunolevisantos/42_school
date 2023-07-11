#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		s;
	int		e;
	int		words;

	split = 0;
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			words++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
	}
	split = malloc(sizeof(char **) * words + 1);
	i = 0;
	words = 0;
	split[words] = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			s = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			e = i;
			split[words] = malloc(sizeof(char *) * (i - s + 1));
			while (s <= e)
				split[words][j++] = str[s++];
			split[words][j] = 0;
			words++;
		}
	}
	return (split);
}

int	main(int ac, char	**av)
{
	int		i;
	int		j;
	int		first;
	char	**arr;

	i = 0;
	first = 1;
	arr = 0;
	if (ac == 2)
	{
		arr = ft_split(av[1]);
		while (arr[i])
			i++;
		i--;
		while(i >= 0)
		{
			j = 0;
			while (arr[i][j])
				write (1, &arr[i][j++], 1);
			if (first)
				write (1, " ", 1);
			first = 0;
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}