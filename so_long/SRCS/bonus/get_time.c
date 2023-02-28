/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:49:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/28 11:52:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

time_t	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, 0);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}
