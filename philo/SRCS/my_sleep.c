/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:30:14 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/20 14:30:38 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	my_sleep(int wait)
{
	time_t	start;

	start = get_time();
	while (get_time() < start + wait)
		usleep(200);
}
