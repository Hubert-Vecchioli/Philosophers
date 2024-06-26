/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_planning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:40:46 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/26 12:58:16 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_max(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}

long	ft_compute_time_to_think(t_philo *philosopher)
{
	if (philosopher->philo_pack->count_philo % 2 == 0)
		return (ft_max(philosopher->philo_pack->time_to_eat - philosopher->philo_pack->time_to_sleep, 0));
	else
	{
		if (philosopher->philo_pack->count_philo == 1)
			return (philosopher->philo_pack->time_to_die * 2);
		else if (philosopher->philo_pack->count_philo == 3)
			return (ft_max(philosopher->philo_pack->time_to_eat * 2 - philosopher->philo_pack->time_to_sleep, 0));
		else 
		{		
			if (philosopher->id <= philosopher->philo_pack->count_philo - 4)
			{}	// (id - 1) / 2 
			else
			{}	//4
				//3
				//2
				//1	
		}
	}
}

void	ft_delayed_start(t_philo *philosopher)
{
	if (!philosopher->philo_pack->is_ended)
	{
		if (philosopher->philo_pack->count_philo == 1)
			ft_think(philosopher);
		//delay compute
	}
	else
		return (0);
}
