/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:57:20 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/15 16:04:42 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}


int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_philo		*curr;
	int			i;
	int			*a;
	int			*res;
	int			globalSum;

	globalSum = 0;
	fill_philos(PHILSNO);
	printf("first phil i = %d\n", table()->first_phil->i);
	printf("last phil i = %d\n", table()->last_phil->i);
	curr = table()->first_phil;
	i = 0;
	while (i < PHILSNO)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&curr->thread, 0, &routine, a) != 0)
			perror ("Failed to create thread");
		i++;
		curr = curr->next;
	}
	curr = table()->first_phil;
	i = 0;
	while (i < PHILSNO)
	{
		if (pthread_join(curr->thread, (void **) &res) != 0)
			perror ("Failed to join thread");
		globalSum += *res;
		free(res);
		i++;
		curr = curr->next;
	}
	printf("global sum: %d\n", globalSum);
	free_philos();
	return (0);
}
