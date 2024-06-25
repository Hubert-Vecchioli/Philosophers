/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/24 23:30:33 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo_pack
{
	long				start_time;
	int					count_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eat_philo_must_eat;
	pthread_mutex_t		*writing_stdout;
	t_philo 			*philos;
} t_philo_pack;

typedef struct s_philo
{
	pthread_t		thread_ref;
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

#endif