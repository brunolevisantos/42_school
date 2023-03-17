/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:30 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 16:50:51 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_philos(void)
{
	t_philo	*curr;
	t_philo	*curr_free;

	curr = table()->first_phil;
	while (curr)
	{
		curr_free = curr;
		curr = curr->next;
		pthread_mutex_destroy(&curr_free->fork);
		pthread_mutex_destroy(&curr_free->Mtx_lastEaten);
		pthread_mutex_destroy(&curr_free->Mtx_imFull);
		// free(curr_free);
	}
	pthread_mutex_destroy(&table()->Mtx_evryPhilFull);
	pthread_mutex_destroy(&table()->Mtx_kill);
}
