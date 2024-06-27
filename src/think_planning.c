/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_planning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:40:46 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/27 19:54:39 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_max(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}

long	ft_compute_time_to_think(t_philo *philosopher)
{
	long tt_eat;

	tt_eat = philosopher->philo_pack->time_to_eat;
	if (philosopher->philo_pack->count_philo % 2 == 0)
		return (ft_max(tt_eat - philosopher->philo_pack->time_to_sleep, 0));
	else
	{
		if (philosopher->philo_pack->count_philo == 1)
			return (philosopher->philo_pack->time_to_die * 2);
		else if (philosopher->philo_pack->count_philo == 3)
			return (ft_max(tt_eat * 2 - philosopher->philo_pack->time_to_sleep, 0));
		else
		{
			if (philosopher->id == philosopher->philo_pack->count_philo - 2)
				return (ft_compute_time_to_think_odd(philosopher->id - 1, philosopher->count_meals, philosopher));
			else if (philosopher->id == philosopher->philo_pack->count_philo - 1)
				return (ft_compute_time_to_think_odd(1, philosopher->count_meals + 1, philosopher));
			else if (philosopher->id == philosopher->philo_pack->count_philo)
				return (ft_compute_time_to_think_odd(1, philosopher->count_meals + 1, philosopher));
			else
				return (ft_compute_time_to_think_odd(philosopher->id, philosopher->count_meals, philosopher));
		}
	}
}

long	ft_compute_time_to_think_odd(int id, int count_meals, t_philo *philosopher)
{
	if (((philosopher->philo_pack->count_philo / 2 -(id - 1) / 2 + count_meals - 1) % (philosopher->philo_pack->count_philo / 2)) <= 1)
		return (ft_max(philosopher->philo_pack->time_to_eat + philosopher->philo_pack->time_to_eat / 2 - philosopher->philo_pack->time_to_sleep, 0));
	else
		return (ft_max(philosopher->philo_pack->time_to_eat - philosopher->philo_pack->time_to_sleep, 0));
}
int	ft_staggered_start(t_philo *philosopher)
{
	int	count_philo;
	
	count_philo = philosopher->philo_pack->count_philo;
	if (count_philo % 2 == 0)
		return (1);
	if (count_philo % 2 == 1 && count_philo > 3 && philosopher->id <= count_philo - 3)
		return (1);
	return (0);
}

void	ft_delayed_start(t_philo *philosopher)
{
	int	count_philo;
	
	count_philo = philosopher->philo_pack->count_philo;
	pthread_mutex_lock(&philosopher->philo_pack->end);
	if (philosopher->philo_pack->is_ended)
	{
		pthread_mutex_unlock(&philosopher->philo_pack->end);
		return ;
	}
	pthread_mutex_unlock(&philosopher->philo_pack->end);
	if (count_philo == 1)
		ft_think(philosopher);
	else if ((ft_staggered_start(philosopher) == 1 && philosopher->id % 2 == 1) || (count_philo == 3 && philosopher->id == 1))
		return ;
	else if ((ft_staggered_start(philosopher) == 1 && philosopher->id % 2 == 0) || (count_philo == 3 && philosopher->id == 2))
		ft_usleep(philosopher, philosopher->philo_pack->time_to_eat);
	else if ((count_philo == 3 && philosopher->id == 3))
		ft_usleep(philosopher, philosopher->philo_pack->time_to_eat * 2);
	else if (count_philo > 3 && count_philo % 2 == 1 && philosopher->id == count_philo - 2)
		ft_usleep(philosopher, philosopher->philo_pack->time_to_eat * 2);
	else if (count_philo > 3 && count_philo % 2 == 1 && philosopher->id == count_philo - 1)
		ft_usleep(philosopher, philosopher->philo_pack->time_to_eat / 2);
	else if (count_philo > 3 && count_philo % 2 == 1 && philosopher->id == count_philo)
		ft_usleep(philosopher, philosopher->philo_pack->time_to_eat + philosopher->philo_pack->time_to_eat / 2);
}
