/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:08:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/21 10:48:27 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	im_full(int *timesEaten)
{
	if (++(*timesEaten) == table()->x_eat)
	{
		pthread_mutex_lock(&table()->mtx_evry_phil_full);
		table()->evry_phil_full++;
		pthread_mutex_unlock(&table()->mtx_evry_phil_full);
	}
}

void	state_print(int i, char *msg)
{
	pthread_mutex_lock(&table()->mtx_kill);
	if (!table()->kill)
	{
		pthread_mutex_unlock(&table()->mtx_kill);
		printf("%ld %d %s", get_time(), i, msg);
		return ;
	}
	pthread_mutex_unlock(&table()->mtx_kill);
}

void	nham_nham(t_philo *curr)
{
	pthread_mutex_lock(get_mutex(curr->i));
	pthread_mutex_lock(get_mutex_next(curr->i));
	pthread_mutex_lock(&curr->mtx_last_eaten);
	curr->last_eaten = get_time();
	pthread_mutex_unlock(&curr->mtx_last_eaten);
	state_print(curr->i, "has taken a fork\n");
	state_print(curr->i, "has taken a fork\n");
	state_print(curr->i, "is eating\n");
	my_sleep(table()->tte);
	im_full(&curr->times_eaten);
	pthread_mutex_unlock(get_mutex(curr->i));
	pthread_mutex_unlock(get_mutex_next(curr->i));
}

void	*routine(void *arg)
{	
	t_philo	*curr;

	curr = (t_philo *)arg;
	if (curr->i % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&table()->mtx_kill);
	while (!table()->kill)
	{
		pthread_mutex_unlock(&table()->mtx_kill);
		state_print(curr->i, "is thinking\n");
		if (curr->last_eaten <= table()->tte + table()->tts + 1)
			usleep(100);
		nham_nham(curr);
		state_print(curr->i, "is sleeping\n");
		my_sleep(table()->tts);
		pthread_mutex_lock(&table()->mtx_kill);
	}
	pthread_mutex_unlock(&table()->mtx_kill);
	return (0);
}
