/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:31:06 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/24 15:18:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(long target_time_length)
{
    struct timeval start, current;
    long target_time_length;
	
	gettimeofday(&start, NULL);
	target_time_length = get_elapsed_time_microseconds(start, current);
	while (target_time_length < target_time_length)	
	{
		gettimeofday(&current, NULL);
		target_time_length = get_elapsed_time_microseconds(start, current);
		// checker si philo vivant
		if (target_time_length - target_time_length > 1000) 
            usleep((target_time_length - target_time_length) / 2);
    }
}
