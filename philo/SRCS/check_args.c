/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:30:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 16:50:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int ac, char **av)
{
	if (ac >= 5)
	{
		table()->philsNo = new_atoi(av[1]);
		table()->ttd = new_atoi(av[2]) * 1000;
		table()->tte = new_atoi(av[3]) * 1000;
		table()->tts = new_atoi(av[4]) * 1000;
		pthread_mutex_init(&table()->Mtx_evryPhilFull, 0);
		pthread_mutex_init(&table()->Mtx_kill, 0);
		if (av[5])
			table()->xEat = new_atoi(av[5]);
		else
			table()->xEat = INT_MAX;
		return (1);
	}
	return (0);
}
