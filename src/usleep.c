/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:31:06 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/27 17:01:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philosopher, long target_time_in_ms)
{
	long int	current_time;

	current_time = 0;
	current_time = ft_get_time();
	if (target_time_in_ms == 0)
		return (1);
	while ((ft_get_time() - current_time) < target_time_in_ms)	
	{
		pthread_mutex_lock(&philosopher->philo_pack->end);
		if (philosopher->philo_pack->is_ended)
			return (pthread_mutex_unlock(&philosopher->philo_pack->end), 0);
		pthread_mutex_unlock(&philosopher->philo_pack->end);
		if (target_time_in_ms - (ft_get_time() - current_time) > 100) 
            usleep((ft_get_time() - current_time)/2); //(target_time_length - target_time_length) / 2
    }
	return (1);
}

long	ft_get_time_diff(long start)
{
	long cur;

	cur = ft_get_time();
	return (cur - start);
}

long	ft_get_time(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		return (0);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}
