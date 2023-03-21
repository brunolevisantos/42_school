/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:30:14 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/21 10:41:20 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	my_sleep(int wait)
{
	time_t	start;

	start = get_time();
	while (get_time() < start + wait)
	{
		// pthread_mutex_lock(&table()->mtx_kill);
		// if (table()->kill)
		// {
		// 	pthread_mutex_unlock(&table()->mtx_kill);
		// 	break ;
		// }
		// pthread_mutex_unlock(&table()->mtx_kill);
		usleep(200);
	}
}
