/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 03:54:58 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 04:02:36 by hvecchio         ###   ########.fr       */
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

int	ft_count_eaten_target_reached(t_philo philosopher)
{
	return (philosopher.count_meals
		>= philosopher.philo_pack->max_eat_philo_must_eat
		&& philosopher.philo_pack->max_eat_philo_must_eat != -1);
}
