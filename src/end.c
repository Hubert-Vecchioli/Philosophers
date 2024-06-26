/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/26 16:07:45 by hvecchio         ###   ########.fr       */
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
	if (err == 'x')
		printf("Error: Mutex failed\n");
	if (err == 't')
		printf("Error: pThread failed\n");
	exit(0);
}
void	ft_free(t_philo_pack *philo_pack)
{
	int	i;
	// free les philos
	pthread_mutex_destroy(philo_pack->writing_stdout);
	i = 0;
	while (i < philo_pack->count_philo)
	{
		pthread_join(philo_pack->philos[i].thread_ref, NULL);
		pthread_mutex_destroy(philo_pack->writing_stdout);
		pthread_mutex_destroy(philo_pack->philos[i].left_fork);
		free(&philo_pack->philos[i]);
	}
}
