/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:30 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/15 15:26:51 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_philos(void)
{
	int		i;
	t_philo	*curr;
	t_philo	*curr_free;

	i = 0;
	curr = table()->first_phil;
	while (curr)
	{
		curr_free = curr;
		curr = curr->next;
		pthread_mutex_destroy(&curr_free->fork);
		free(curr_free);
	}
}
