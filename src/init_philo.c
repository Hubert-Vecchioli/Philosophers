/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:24:30 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 11:59:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_threads(t_philo_pack *philo_pack)
{
	int			i;
	pthread_t	t_end_control;

	i = -1;
	while (++i < philo_pack->count_philo)
		philo_pack->philos[i].start_time_last_eat = ft_get_time();
	philo_pack->start_time = ft_get_time();
	i = -1;
	while (++i < philo_pack->count_philo)
	{
		if (pthread_create(&(philo_pack->philos[i].thread_ref),
				NULL, &ft_orchestrate, &(philo_pack->philos[i])))
			return (ft_free(philo_pack), ft_error('t'), 0);
	}
	if (philo_pack->count_philo > 1)
	{
		if (pthread_create(&t_end_control, NULL, &ft_end_control, (philo_pack)))
			return (ft_free(philo_pack), ft_error('t'), 0);
		pthread_join(t_end_control, NULL);
	}
	return (1);
}

int	ft_init_philos(t_philo_pack *philo_pack)
{
	int	i;

	i = -1;
	philo_pack->philos = malloc(sizeof(t_philo) * philo_pack->count_philo);
	if (philo_pack->philos == NULL)
		return (ft_error('m'), 0);
	while (++i < philo_pack->count_philo)
	{
		philo_pack->philos[i].philo_pack = philo_pack;
		philo_pack->philos[i].id = i + 1;
		philo_pack->philos[i].start_time_last_eat = 0;
		philo_pack->philos[i].count_meals = 0;
		if (pthread_mutex_init(&philo_pack->philos[i].finished_eating, NULL))
			return (ft_free(philo_pack), ft_error('x'), 0);
		printf("philo: %d finished_eating :%p\n",philo_pack->philos[i].id,&philo_pack->philos[i].finished_eating);
		if (pthread_mutex_init(&philo_pack->philos[i].started_eating, NULL))
			return (ft_free(philo_pack), ft_error('x'), 0);
		printf("philo: %d started_eating :%p\n",philo_pack->philos[i].id,&philo_pack->philos[i].started_eating);
		if (pthread_mutex_init(&philo_pack->philos[i].left_fork, NULL))
			return (ft_free(philo_pack), ft_error('x'), 0);
		printf("philo: %d left_fork :%p\n",philo_pack->philos[i].id,&philo_pack->philos[i].left_fork);
		if (i > 0)
			philo_pack->philos[i - 1].right_fork
				= &philo_pack->philos[i].left_fork;
		if (i + 1 == philo_pack->count_philo && i > 0)
			philo_pack->philos[i].right_fork = &philo_pack->philos[0].left_fork;
	}
	return (1);
}
