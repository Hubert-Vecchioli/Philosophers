/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/25 16:58:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_delayed_start(t_philo *philosopher)
{
	if (philosopher->philo_pack->count_philo == 1)
		ft_think(philosopher)
}

int	ft_eat(t_philo *philosopher)
{
	//check if we can keep it on
}

int	ft_sleep(t_philo *philosopher)
{
	if (!philosopher->philo_pack->is_ended)
		return (, 0);
	//check if we can keep it on
}


int	ft_think(t_philo *philosopher)
{
	if (philosopher->philo_pack->count_philo == 1)
		ft_think(philosopher)
	//check if we can keep it on
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

int	ft_end_control(t_philo_pack *philo_pack)
{
	int	i;
	int	j;

	while (!philo_pack->is_ended)
	{
		i = 0;
		j = 0;
		while (i < philo_pack->count_philo)
		{
			//check si mort
				// action mort
				// return (0);
			if (philo_pack->philos[i].count_meals >= philo_pack->count_philo)
				j++;
		}
		if (j == philo_pack->count_philo)
		{}	// action de fin
	}
}
