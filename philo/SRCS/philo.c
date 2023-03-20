/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:57:20 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:10 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

int	chrono_last_eaten(t_philo *curr)
{
	pthread_mutex_lock(&curr->mtx_last_eaten);
	if (get_time() > (curr->last_eaten + table()->ttd))
	{
		pthread_mutex_unlock(&curr->mtx_last_eaten);
		pthread_mutex_lock(&table()->mtx_kill);
		table()->kill = 1;
		printf("%ld %d died\n", get_time(), curr->i);
		pthread_mutex_unlock(&table()->mtx_kill);
		return (0);
	}
	pthread_mutex_unlock(&curr->mtx_last_eaten);
	return (1);
}

int	go_or_kill(void)
{
	t_philo		*curr;

	curr = table()->first_phil;
	while (curr)
	{
		pthread_mutex_lock(&curr->mtx_last_eaten);
		if (get_time() > (curr->last_eaten + table()->ttd))
		{
			pthread_mutex_unlock(&curr->mtx_last_eaten);
			pthread_mutex_lock(&table()->mtx_kill);
			table()->kill = 1;
			printf("%ld %d died\n", get_time(), curr->i);
			pthread_mutex_unlock(&table()->mtx_kill);
			return (0);
		}
		pthread_mutex_unlock(&curr->mtx_last_eaten);
		pthread_mutex_lock(&table()->mtx_evry_phil_full);
		if (table()->evry_phil_full >= table()->phils_no)
		{
			pthread_mutex_lock(&table()->mtx_kill);
			table()->kill = 1;
			pthread_mutex_unlock(&table()->mtx_kill);
			pthread_mutex_unlock(&table()->mtx_evry_phil_full);
			return (0);
		}
		pthread_mutex_unlock(&table()->mtx_evry_phil_full);
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
		table()->start_run = get_time();
		while (curr)
		{
			if (pthread_create(&curr->thread, 0, &routine, curr) != 0)
				printf("Failed to create thread");
			curr = curr->next;
		}
		while (go_or_kill())
			;
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
