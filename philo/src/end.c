/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 11:38:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char err)
{
	if (err == 'i')
		printf("Error: Wrong arg number\n");
	if (err == 'd')
		printf("Error: inputs are not valid digits\n");
	if (err == '0')
		printf("Error: no philosopher in the input\n");
	if (err == 'm')
		printf("Error: Malloc failed\n");
	if (err == 'n')
		printf("0 1 died\n");
	if (err == 'w')
		printf("No meal to eat\n");
	if (err == 'x')
		printf("Error: Mutex failed\n");
	if (err == 't')
		printf("Error: pThread failed\n");
	exit(0);
}

void	ft_free(t_philo_pack *philo_pack)
{
	int	i;

	i = -1;
	while (++i < philo_pack->count_philo)
	{
		pthread_join(philo_pack->philos[i].thread_ref, NULL);
	}
	i = -1;
	while (++i < philo_pack->count_philo)
	{
		pthread_mutex_destroy(&philo_pack->philos[i].left_fork);
		pthread_mutex_destroy(&philo_pack->philos[i].started_eating);
		pthread_mutex_destroy(&philo_pack->philos[i].finished_eating);
	}
	pthread_mutex_destroy(&(philo_pack->writing_stdout));
	pthread_mutex_destroy(&(philo_pack->end));
	if (philo_pack->philos)
		free(philo_pack->philos);
}
