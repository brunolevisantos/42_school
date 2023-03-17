/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:18:13 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 13:18:33 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, 0);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}
