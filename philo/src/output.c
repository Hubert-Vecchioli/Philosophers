/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:30:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 10:55:40 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_util(t_philo *philosopher, char message)
{
	if (message == 'l')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time),
			philosopher->id, "has taken a fork");
	else if (message == 'r')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time),
			philosopher->id, "has taken a fork");
	else if (message == 'e')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time),
			philosopher->id, "is eating");
	else if (message == 's')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time),
			philosopher->id, "is sleeping");
	else if (message == 't')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time),
			philosopher->id, "is thinking");
}

int	ft_print(t_philo *philosopher, char message)
{
	pthread_mutex_lock(&philosopher->philo_pack->writing_stdout);
	if (message == 'd')
		printf("%ld %d %s\n", ft_get_time_diff
			(philosopher->philo_pack->start_time), philosopher->id, "died");
	pthread_mutex_lock(&philosopher->philo_pack->end);
	if (!philosopher->philo_pack->is_ended)
	{
		pthread_mutex_unlock(&philosopher->philo_pack->end);
		ft_print_util(philosopher, message);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->philo_pack->end);
		pthread_mutex_unlock(&philosopher->philo_pack->writing_stdout);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->philo_pack->writing_stdout);
	return (1);
}
