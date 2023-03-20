/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:30:24 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/20 12:36:00 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo{
	int				i;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct timeval	t;
	pthread_mutex_t	mtx_last_eaten;
	time_t			last_eaten;
	pthread_mutex_t	mtx_im_full;
	int				times_eaten;
}	t_philo;

typedef struct s_table{
	t_philo			*first_phil;
	t_philo			*last_phil;
	int				phils_no;
	int				ttd;
	int				tte;
	int				tts;
	int				x_eat;
	pthread_mutex_t	mtx_evry_phil_full;
	int				evry_phil_full;
	pthread_mutex_t	mtx_kill;
	int				kill;
	time_t			start_run;
}	t_table;

t_table			*table(void);
void			*routine(void *arg);
void			fill_philos(int philsNo);
void			free_philos(void);
void			*ft_calloc(size_t size);
pthread_mutex_t	*get_mutex(int index);
pthread_mutex_t	*get_mutex_next(int index);
int				new_atoi(char *str);
int				check_args(int ac, char **av);
time_t			get_time(void);

#endif