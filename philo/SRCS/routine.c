/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:08:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 18:50:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	im_full(int *timesEaten)
{
	if (++(*timesEaten) == table()->xEat)
	{
		pthread_mutex_lock(&table()->Mtx_evryPhilFull);
		table()->evryPhilFull++;
		pthread_mutex_unlock(&table()->Mtx_evryPhilFull);
	}
}

void	state_print(int i, char *msg)
{
	pthread_mutex_lock(&table()->Mtx_kill);
	if (!table()->kill)
	{
		pthread_mutex_unlock(&table()->Mtx_kill);
		printf("%ld %d %s", get_time(), i, msg);
		return ;
	}
	pthread_mutex_unlock(&table()->Mtx_kill);
}

void	*routine(void *arg)
{	
	int	i;
	t_philo curr;
	
	curr = *(t_philo*)arg;
	i = 0;
	pthread_mutex_lock(&curr.Mtx_lastEaten);
	curr.lastEaten = get_time();
	pthread_mutex_unlock(&curr.Mtx_lastEaten);
	if (curr.i % 2 == 0)
		usleep(10);
	pthread_mutex_lock(&table()->Mtx_kill);
	while (!table()->kill)
	{
		pthread_mutex_unlock(&table()->Mtx_kill);
		state_print(curr.i, "is thinking\n");
		pthread_mutex_lock(get_mutex(curr.i));
		pthread_mutex_lock(get_mutex_next(curr.i));
		state_print(curr.i, "has taken a fork\n");
		state_print(curr.i, "has taken a fork\n");
		state_print(curr.i, "is eating\n");
		im_full(&curr.timesEaten);
		pthread_mutex_lock(&curr.Mtx_lastEaten);
		curr.lastEaten = get_time();
		pthread_mutex_unlock(&curr.Mtx_lastEaten);
		usleep(table()->tte);
		pthread_mutex_unlock(get_mutex(curr.i));
		pthread_mutex_unlock(get_mutex_next(curr.i));
		state_print(curr.i, "is sleeping\n");
		usleep(table()->tts);
		i++;
		pthread_mutex_lock(&table()->Mtx_kill);
	}
	pthread_mutex_unlock(&table()->Mtx_kill);
	return (0);
}
