/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:57:20 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/15 23:57:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*get_mutex(int index)
{
	t_philo	*curr;
	
	curr = table()->first_phil;
	while (index != curr->i)
		curr = curr->next;
	return (&curr->fork);
}

pthread_mutex_t	*get_mutex_next(int index)
{
	t_philo	*curr;
	int		index_next;

	index_next = index + 1;
	if (index == PHILSNO - 1)
		return (&(table()->first_phil)->fork);
	curr = table()->first_phil;
	while (index_next != curr->i)
		curr = curr->next;
	return (&curr->fork);
}

void	*routine(void *arg)
 {	
	int	index  = *(int*)arg;
	pthread_mutex_t	*mutexCurr = get_mutex(index);
	pthread_mutex_t	*mutexNext = get_mutex_next(index);
	// t_philo	curr;

	// curr = *(t_philo*)arg;
	// index = *(int*)arg;
	pthread_mutex_lock(mutexCurr);
	pthread_mutex_lock(mutexNext); //chamar so uma vez cada funcao get e guardar num pointer dentro da routine
	printf ("Philo %d takes a fork\n", index);
	sleep(5);
	pthread_mutex_unlock(mutexCurr);
	pthread_mutex_unlock(mutexNext);
	free(arg);
	return (0);
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

	fill_philos(PHILSNO);
	printf("first phil i = %d\n", table()->first_phil->i);
	printf("last phil i = %d\n", table()->last_phil->i);
	curr = table()->first_phil;
	i = 0;
	while (i < PHILSNO)
	{
		a = malloc(sizeof(int));
		*a = curr->i;
		if (pthread_create(&curr->thread, 0, &routine, curr) != 0)
			perror ("Failed to create thread");
		i++;
		curr = curr->next;
	}
	curr = table()->first_phil;
	i = 0;
	while (i < PHILSNO)
	{
		if (pthread_join(curr->thread, 0) != 0)
			perror ("Failed to join thread");
		i++;
		curr = curr->next;
	}
	free_philos();
	return (0);
}
