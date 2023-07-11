#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i;
	int	size;
	int	j;
	int	e;

	arr = 0;
	j = 0;
	e = end;
	i = start;
	if (end < start)
		size = start - end;
	else
		size = end - start;
	if (start <= end)
	{
		arr = malloc(sizeof(int) * (size + 1));
		while (j <= size)
		{
			arr[j] = i;
			i++;
			j++;
		}
	}
	else
	{
		arr = malloc(sizeof(int) * (size + 1));
		while (j < size)
		{
			arr[j] = i;
			i--;
			j++;
		}
	}
	i = 0;
	return (arr);
}

int	main(void)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_range(2, -4);
	while (arr[i])
		printf("%d\n", arr[i++]);
}