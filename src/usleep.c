/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:31:06 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/25 19:28:01 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philosopher, long target_time_length)
{
    struct timeval start;
	struct timeval cur;
    long target_time_length;
	
	gettimeofday(&start, NULL);
	gettimeofday(&cur, NULL);
	target_time_length = (cur.tv_sec  - start.tv_sec) * 1000000  + cur.tv_usec - start.tv_usec;
	while (target_time_length < target_time_length)	
	{
		if (philosopher->philo_pack->is_ended)
			return (0); // trigger a is dead ? but why have a monitor?
		gettimeofday(&cur, NULL);
		target_time_length = (cur.tv_sec  - start.tv_sec) * 1000000  + cur.tv_usec - start.tv_usec;
		if (target_time_length - target_time_length > 1000) 
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
