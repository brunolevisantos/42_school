#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			words++;
			while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			s = i;
			while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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

// int	main(void)
// {
// 	int	i;
// 	char	**arr = ft_split("     A   	tua 	mae    e um homem   	");

// 	i = 0;
// 	while (arr[i])
// 		printf("%s\n", arr[i++]);
// }