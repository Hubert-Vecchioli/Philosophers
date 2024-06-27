/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/27 19:57:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork);
	ft_print(philosopher, 'l');
	printf("philo %d %p\n", philosopher->id,&philosopher->left_fork);
	pthread_mutex_lock(philosopher->right_fork);
	ft_print(philosopher, 'r');
	printf("philo %d %p\n", philosopher->id,&philosopher->right_fork);
	pthread_mutex_lock(&philosopher->started_eating);
	pthread_mutex_lock(&philosopher->philo_pack->end);
	if (!philosopher->philo_pack->is_ended)
		philosopher->start_time_last_eat = ft_get_time();
	pthread_mutex_unlock(&philosopher->philo_pack->end);
	ft_print(philosopher, 'e');
	pthread_mutex_unlock(&philosopher->started_eating);
	if (!ft_usleep(philosopher, philosopher->philo_pack->time_to_eat))
		return (pthread_mutex_unlock(&philosopher->left_fork), pthread_mutex_unlock(philosopher->right_fork), 0);
	pthread_mutex_lock(&philosopher->started_eating);
	philosopher->count_meals++;
	pthread_mutex_unlock(&philosopher->started_eating);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(&philosopher->left_fork);
	return (1);
}

int	ft_sleep(t_philo *philosopher)
{
	if (!ft_print(philosopher, 's'))
		return (0);
	if (!ft_usleep(philosopher, philosopher->philo_pack->time_to_sleep))
		return (0);
	return (1);
}

int	ft_think(t_philo *philosopher)
{
	// if (ft_compute_time_to_think(philosopher) == 0)
	// 	return (1);
	if (!ft_print(philosopher, 't'))
		return (0);
	if (!ft_usleep(philosopher, ft_compute_time_to_think(philosopher)))
		return (0);
	// if (!ft_usleep(philosopher, 10))
	// 	return (0);
	return (1);
}

void	*ft_orchestrate(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	ft_delayed_start(philosopher);
	while (1)
	{
		if (!ft_eat(philosopher))
			return (NULL);
		if (!ft_sleep(philosopher))
			return (NULL);
		if (!ft_think(philosopher))
			return (NULL);
	}
	return (NULL);
}

void	*ft_end_control(void *philo_p)
{
	int				i;
	int				j;
	t_philo_pack	*philo_pack;

	philo_pack = (t_philo_pack *)philo_p;
	while (!philo_pack->is_ended)
	{
		i = -1;
		j = 0;
		while (++i < philo_pack->count_philo)
		{
			pthread_mutex_lock(&philo_pack->philos[i].started_eating);
			if (philo_pack->time_to_die <= ft_get_time_diff(
					philo_pack->philos[i].start_time_last_eat))
			{
				pthread_mutex_unlock(&philo_pack->philos[i].started_eating);
				pthread_mutex_lock(&philo_pack->end);
				philo_pack->is_ended = 1;
				pthread_mutex_unlock(&philo_pack->end);
				ft_print(&philo_pack->philos[i], 'd');
				return (NULL);
			}
			if (philo_pack->philos[i].count_meals
				>= philo_pack->max_eat_philo_must_eat
				&& philo_pack->max_eat_philo_must_eat != -1)
				j++;
			pthread_mutex_unlock(&philo_pack->philos[i].started_eating);

		}
		if (j == philo_pack->count_philo)
		{
			pthread_mutex_lock(&philo_pack->end);
			philo_pack->is_ended = 1;
			pthread_mutex_unlock(&philo_pack->end);
			return (NULL);
		}	
	}
	return (NULL);
}
