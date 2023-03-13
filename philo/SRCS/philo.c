#include "../include/philo.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{	
	int	index;
	int	j;
	int	sum;

	index = *(int*)arg;
	j = 0;
	sum = 0;
	while (j < 5)
		sum += primes[index + j++];
	printf ("local sum: %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	pthread_t th[2];
	int	i;
	int	*a;
	int	*res;
	int	globalSum;

	globalSum = 0;
	// i = 0;
	// while (i++ < 2)
	for (i = 0; i < 2; i++)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], 0, &routine, a) != 0)
			perror ("Failed to create thread");
	}
	// i = 0;
	// while (i++ < 2)
	for (i = 0; i < 2; i++)
	{
		if (pthread_join(th[i], (void **) &res) != 0)
			perror ("Failed to join thread");
		globalSum += *res;
		free(res);
	}
	printf("global sum: %d\n", globalSum);
	return (0);
}