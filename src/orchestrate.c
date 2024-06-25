/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/25 19:30:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_delayed_start(t_philo *philosopher)
{
	if (!philosopher->philo_pack->is_ended)
	{
		//
	}
	else
		return (0);
	if (philosopher->philo_pack->count_philo == 1)
		ft_think(philosopher);
}

int	ft_eat(t_philo *philosopher)
{
	if (!philosopher->philo_pack->is_ended)
		ft_print(philosopher, 'e');
	else
		return (0);
	if(ft_usleep(philosopher, philosopher->philo_pack->time_to_eat))
		return (0);
	return (1);
}

int	ft_sleep(t_philo *philosopher)
{
	if (!philosopher->philo_pack->is_ended)
		ft_print(philosopher, 's');
	else
		return (0);	
	if (ft_usleep(philosopher, philosopher->philo_pack->time_to_sleep))
		return (0);	
	return (1);
}


int	ft_think(t_philo *philosopher)
{
	long time_to_think;
	
	if (philosopher->philo_pack->count_philo == 1)
		ft_sleep(philosopher->philo_pack->time_to_die);
	if (!philosopher->philo_pack->is_ended)
		ft_print(philosopher, 't');
	else
		return (0);	
	// time_to_think = ft_compute_time_to_think(philosopher);
	if (ft_usleep(philosopher, time_to_think));
		return (0);	
	return (1);
}

void	ft_orchestrate(t_philo *philosopher)
{
	ft_delayed_start(philosopher);
	while (1)
	{
		if (ft_eat(philosopher))
			return (NULL);
		if (ft_sleep(philosopher))
			return (NULL);
		if (ft_think(philosopher))
			return (NULL);
	}
}

void	ft_end_control(t_philo_pack *philo_pack)
{
	int	i;
	int	j;

	while (!philo_pack->is_ended)
	{
		i = 0;
		j = 0;
		while (i < philo_pack->count_philo)
		{
			if(philo_pack->time_to_die <= ft_get_time_diff_to_now(philo_pack->philos[i].start_time_last_eat))
			{
				philo_pack->is_ended = 1;
				philo_pack->philos[i].is_dead = 1;
				ft_print(&philo_pack->philos[i], 'd');
				// trigger stop
				// return (0);
			}
			if (philo_pack->philos[i].count_meals >= philo_pack->count_philo)
				j++;
		}
		if (j == philo_pack->count_philo)
		{
			philo_pack->is_ended = 1;
			// print all eaten?
			// trigger stop
			// return (0);
		}	
	}
	// return (1);
}

void	ft_print(t_philo *philosopher, char message)
{
	pthread_mutex_lock(&philosopher->philo_pack->writing_stdout);
	// check if alive
	if (message == 'd')
	// print dead
	else if (message == 'e')
	// print eat
	else if (message == 's')
	// print sleep
	else if (message == 't')
	// print think
	pthread_mutex_unlock(&philosopher->philo_pack->writing_stdout);
}
