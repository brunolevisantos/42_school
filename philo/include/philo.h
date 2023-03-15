/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:30:24 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/15 23:08:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PHILSNO 4

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <pthread.h>
# include <time.h>


typedef struct s_philo{
	int				i;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_table{
	t_philo	*first_phil;
	t_philo	*last_phil;
}	t_table;


t_table	*table(void);
void	fill_philos(int philsNo);
void	free_philos(void);
void	*ft_calloc(size_t size);
pthread_mutex_t	*get_mutex(int index);

#endif