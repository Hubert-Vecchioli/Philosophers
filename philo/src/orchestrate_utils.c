/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 03:54:58 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 18:10:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_has_philo_died(t_philo_pack	*philo_pack, int i)
{
	return (philo_pack->time_to_die <= ft_get_time_diff
		(philo_pack->philos[i].start_time_last_eat));
}

long	ft_max(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	ft_update_end(t_philo_pack *philo_pack, int i)
{
	if (i != -1)
		pthread_mutex_unlock(&philo_pack->philos[i].started_eating);
	pthread_mutex_lock(&philo_pack->end);
	philo_pack->is_ended = 1;
	pthread_mutex_unlock(&philo_pack->end);
}

int	ft_is_target_eat_reached(t_philo_pack *philo_pack)
{
	int		i;
	int		count_philo_at_target;

	if (philo_pack->max_eat_philo_must_eat == -1)
		return (0);
	count_philo_at_target = 0;
	i = -1;
	while (++i < philo_pack->count_philo)
	{
		pthread_mutex_lock(&philo_pack->philos[i].finished_eating);
		if (philo_pack->philos[i].count_meals
			>= philo_pack->max_eat_philo_must_eat)
			count_philo_at_target++;
		pthread_mutex_unlock(&philo_pack->philos[i].finished_eating);
	}
	if (count_philo_at_target == philo_pack->count_philo)
		return (1);
	return (0);
}

void	ft_solo_philo_life(t_philo *philosopher)
{
	ft_print(philosopher, 't');
	ft_usleep(philosopher, philosopher->philo_pack->time_to_die);
	ft_print(philosopher, 'd');
}
