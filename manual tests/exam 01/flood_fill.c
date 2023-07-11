#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	t_point	iter;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == c)
	{
		iter = begin;
		iter.x += 1;
		flood_fill(tab, size, iter);
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == c)
	{
		iter = begin;
		iter.y += 1;
		flood_fill(tab, size, iter);
	}
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == c)
	{
		iter = begin;
		iter.x -= 1;
		flood_fill(tab, size, iter);
	}
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == c)
	{
		iter = begin;
		iter.y -= 1;
		flood_fill(tab, size, iter);
	}
}
