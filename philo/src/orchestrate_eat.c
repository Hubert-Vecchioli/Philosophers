/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:53:37 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 18:10:25 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat_even(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork);
	ft_print(philosopher, 'l');
	pthread_mutex_lock(philosopher->right_fork);
	ft_print(philosopher, 'r');
	ft_print(philosopher, 'e');
	pthread_mutex_lock(&philosopher->started_eating);
	pthread_mutex_lock(&philosopher->philo_pack->end);
	if (!philosopher->philo_pack->is_ended)
		philosopher->start_time_last_eat = ft_get_time();
	pthread_mutex_unlock(&philosopher->philo_pack->end);
	pthread_mutex_unlock(&philosopher->started_eating);
	if (!ft_usleep(philosopher, philosopher->philo_pack->time_to_eat))
		return (pthread_mutex_unlock(&philosopher->left_fork),
			pthread_mutex_unlock(philosopher->right_fork), 0);
	pthread_mutex_lock(&philosopher->finished_eating);
	philosopher->count_meals++;
	pthread_mutex_unlock(&philosopher->finished_eating);
	pthread_mutex_unlock(&philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
	return (1);
}

int	ft_eat_odd(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	ft_print(philosopher, 'r');
	pthread_mutex_lock(&philosopher->left_fork);
	ft_print(philosopher, 'l');
	ft_print(philosopher, 'e');
	pthread_mutex_lock(&philosopher->started_eating);
	pthread_mutex_lock(&philosopher->philo_pack->end);
	if (!philosopher->philo_pack->is_ended)
		philosopher->start_time_last_eat = ft_get_time();
	pthread_mutex_unlock(&philosopher->philo_pack->end);
	pthread_mutex_unlock(&philosopher->started_eating);
	if (!ft_usleep(philosopher, philosopher->philo_pack->time_to_eat))
		return (pthread_mutex_unlock(&philosopher->left_fork),
			pthread_mutex_unlock(philosopher->right_fork), 0);
	pthread_mutex_lock(&philosopher->finished_eating);
	philosopher->count_meals++;
	pthread_mutex_unlock(&philosopher->finished_eating);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(&philosopher->left_fork);
	return (1);
}
