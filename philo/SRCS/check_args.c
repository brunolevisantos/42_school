/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:30:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/21 10:25:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int ac, char **av)
{
	if (ac >= 5)
	{
		if (new_atoi(av[1]) == 1)
		{
			my_sleep(new_atoi(av[2]));
			printf("%s 1 has died\n", av[2]);
			return (0);
		}
		table()->phils_no = new_atoi(av[1]);
		table()->ttd = new_atoi(av[2]);
		table()->tte = new_atoi(av[3]);
		table()->tts = new_atoi(av[4]);
		pthread_mutex_init(&table()->mtx_evry_phil_full, 0);
		pthread_mutex_init(&table()->mtx_kill, 0);
		if (av[5])
			table()->x_eat = new_atoi(av[5]);
		else
			table()->x_eat = INT_MAX;
		return (1);
	}
	return (0);
}
