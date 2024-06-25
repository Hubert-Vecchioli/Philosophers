/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/25 14:57:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo_pack		t_philo_pack;
typedef struct s_philo			t_philo;

typedef struct s_philo_pack
{
	long				start_time;
	int					count_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eat_philo_must_eat;
	int					is_ended;
	pthread_mutex_t		*writing_stdout;
	pthread_mutex_t		*end;
	t_philo 			*philos;
} t_philo_pack;

typedef struct s_philo
{
	pthread_t		thread_ref;
	t_philo_pack	*philo_pack;
	int				id;
	long 			start_time_last_eat;
	int				is_eating;
	int				is_sleeping;
	int				is_dead;
	int 			count_meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
} t_philo;

void	ft_orchestrate(t_philo *philosopher);
void	ft_end_control(t_philo_pack *philo_pack);

#endif