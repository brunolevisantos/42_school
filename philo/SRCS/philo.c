/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:57:20 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 18:12:06 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

int	go_or_kill(void)
{
	t_philo		*curr;
	
	curr = table()->first_phil;
	while (curr)
	{
		pthread_mutex_lock(&curr->Mtx_lastEaten);
		if (get_time() > (curr->lastEaten + table()->ttd))
		{
			pthread_mutex_unlock(&curr->Mtx_lastEaten);
			pthread_mutex_lock(&table()->Mtx_kill);
			table()->kill = 1;
			printf("%d died", curr->i);
			pthread_mutex_unlock(&table()->Mtx_kill);
			return (0);
		}
		pthread_mutex_unlock(&curr->Mtx_lastEaten);
		pthread_mutex_lock(&table()->Mtx_evryPhilFull);
		if (table()->evryPhilFull >= table()->philsNo)
		{
			pthread_mutex_lock(&table()->Mtx_kill);
			table()->kill = 1;
			pthread_mutex_unlock(&table()->Mtx_kill);
			return (0);
		}
		pthread_mutex_lock(&table()->Mtx_evryPhilFull);
		curr = curr->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo		*curr;

	if (check_args(ac, av))
	{
		fill_philos(new_atoi(av[1]));
		curr = table()->first_phil;
		while (curr)
		{
			if (pthread_create(&curr->thread, 0, &routine, curr) != 0)
				printf("Failed to create thread");
			curr = curr->next;
		}
		// while (go_or_kill())
		// 	;
		curr = table()->first_phil;
		while (curr)
		{
			if (pthread_join(curr->thread, 0) != 0)
				printf("Failed to join thread");
			curr = curr->next;
		}
		free_philos();
	}
	return (0);
}
