/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 17:55:01 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philosopher)
{
	if (philosopher->id % 2 == 0)
		return (ft_eat_even(philosopher));
	else
		return (ft_eat_odd(philosopher));
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
		}
		if (ft_is_target_eat_reached(philo_pack))
			return (ft_update_end(philo_pack, -1), NULL);
	}
	return (NULL);
}
