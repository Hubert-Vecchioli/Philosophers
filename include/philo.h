/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/21 18:42:36 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo_pack
{
	long long int		start_time;
	int					count_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eat_philo_must_eat;
	t_philo 			*philos;
} t_philo_pack;

typedef struct s_philo
{
	pthread_t		thread_ref;
	int				id;
	int 			start_time_last_eat;
	int				is_eating;
	int				is_sleeping;
	int				is_dead;
	int 			count_meals;
} t_philo;

#endif