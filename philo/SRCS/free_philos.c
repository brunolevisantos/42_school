/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:30 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/20 12:39:10 by bde-seic         ###   ########.fr       */
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
		pthread_mutex_destroy(&curr_free->mtx_last_eaten);
		pthread_mutex_destroy(&curr_free->mtx_im_full);
	}
	pthread_mutex_destroy(&table()->mtx_evry_phil_full);
	pthread_mutex_destroy(&table()->mtx_kill);
}
