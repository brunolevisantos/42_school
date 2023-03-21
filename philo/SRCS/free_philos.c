/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:30 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/21 10:20:07 by bde-seic         ###   ########.fr       */
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
		free(curr_free);
	}
	pthread_mutex_destroy(&table()->mtx_evry_phil_full);
	pthread_mutex_destroy(&table()->mtx_kill);
}
