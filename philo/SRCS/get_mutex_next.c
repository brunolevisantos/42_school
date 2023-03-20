/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mutex_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:25:20 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/20 12:37:43 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*get_mutex_next(int index)
{
	t_philo	*curr;
	int		index_next;

	index_next = index + 1;
	if (index == table()->phils_no)
		return (&(table()->first_phil)->fork);
	curr = table()->first_phil;
	while (index_next != curr->i)
		curr = curr->next;
	return (&curr->fork);
}
