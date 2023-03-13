#include "../include/philo.h"

void	*roll_dice()
{	
	int value;
	int *result;

	value = (rand() % 6) + 1;
	result = malloc (sizeof(int));
	*result = value;
	// printf("%d\n", value);
	return ((void*) result);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	pthread_t t1;
	int *res;

	srand(time(0));
	if (pthread_create(&t1, 0, &roll_dice, 0) != 0)
		printf("error on thrad creation\n");
	if (pthread_join(t1, (void **) &res) != 0)
		printf("error on thread waiting\n");
	printf("result: %d\n", *res);
	free (res);
	return (0);
}