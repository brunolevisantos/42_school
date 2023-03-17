/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:24:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/16 14:25:17 by bde-seic         ###   ########.fr       */
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
