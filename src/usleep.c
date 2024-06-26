/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:31:06 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/26 17:22:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philosopher, long target_time_length)
{
    struct timeval start;
	struct timeval cur;
    long curr_time_length;
	
	gettimeofday(&start, NULL);
	gettimeofday(&cur, NULL);
	curr_time_length = (cur.tv_sec  - start.tv_sec) * 1000000  + cur.tv_usec - start.tv_usec;
	while (curr_time_length < target_time_length)	
	{
		pthread_mutex_lock(philosopher->philo_pack->end);
		if (philosopher->philo_pack->is_ended)
			return (pthread_mutex_unlock(philosopher->philo_pack->end), 0);
		pthread_mutex_unlock(philosopher->philo_pack->end);
		gettimeofday(&cur, NULL);
		curr_time_length = (cur.tv_sec  - start.tv_sec) * 1000000  + cur.tv_usec - start.tv_usec;
		if (target_time_length - curr_time_length > 1000) 
            usleep(100); //(target_time_length - target_time_length) / 2
    }
	return (1);
}

long	ft_get_time_diff(struct timeval start)
{
	struct timeval cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec  - start.tv_sec) * 1000000  + cur.tv_usec - start.tv_usec);
}
