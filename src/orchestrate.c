/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 11:46:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philosopher)
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
	if (!ft_print(philosopher, 't'))
		return (0);
	if (!ft_usleep(philosopher, ft_compute_time_to_think(philosopher)))
		return (0);
	return (1);
}

void	*ft_orchestrate(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->philo_pack->count_philo == 1)
		return (ft_solo_philo_life(philosopher), NULL);
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
			if (ft_has_philo_died(philo_pack, i))
			{
				ft_update_end(philo_pack, i);
				return (ft_print(&philo_pack->philos[i], 'd'), NULL);
			}
			pthread_mutex_unlock(&philo_pack->philos[i].started_eating);
			if (ft_count_eaten_target_reached(philo_pack->philos[i]))
				++j;
		}
		usleep(100);
		if (j >= philo_pack->count_philo)
			return (ft_update_end(philo_pack, -1), NULL);
	}
	return (NULL);
}
