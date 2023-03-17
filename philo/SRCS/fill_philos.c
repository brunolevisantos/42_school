/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:04:26 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 18:55:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	fill_philos(int philsNo)
{
	t_philo	*node;
	t_philo	*curr;
	int		i;

	i = 1;
	while (i <= philsNo)
	{
		node = ft_calloc(sizeof(t_philo));
		node->i = i;
		pthread_mutex_init(&node->fork, 0);
		pthread_mutex_init(&node->Mtx_lastEaten, 0);
		pthread_mutex_init(&node->Mtx_imFull, 0);
		node->lastEaten = get_time();
		if (!table()->first_phil)
			table()->first_phil = node;
		else
		{
			curr = table()->first_phil;
			while (curr->next != 0)
				curr = curr->next;
			curr->next = node;
			node->prev = curr;
			table()->last_phil = node;
		}
		i++;
	}
}
