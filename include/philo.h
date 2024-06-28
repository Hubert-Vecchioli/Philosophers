/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 04:02:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo_pack		t_philo_pack;
typedef struct s_philo			t_philo;

typedef struct s_philo_pack
{
	long				start_time;
	int					count_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					max_eat_philo_must_eat;
	int					is_ended;
	pthread_mutex_t		writing_stdout;
	pthread_mutex_t		end;
	t_philo				*philos;
}	t_philo_pack;

typedef struct s_philo
{
	pthread_t			thread_ref;
	t_philo_pack		*philo_pack;
	int					id;
	long				start_time_last_eat;
	int					is_dead;
	int					count_meals;
	pthread_mutex_t		started_eating;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo;

void	*ft_orchestrate(void *philosopher);
void	*ft_end_control(void *philo_p);
void	ft_error(char err);
void	ft_free(t_philo_pack *philo_pack);
void	ft_init_pack(int ac, char **av, t_philo_pack *philo_pack);
void	ft_delayed_start(t_philo *philosopher);
int		ft_init_threads(t_philo_pack *philo_pack);
int		ft_init_philos(t_philo_pack *philo_pack);
int		ft_eat(t_philo *philosopher);
int		ft_sleep(t_philo *philosopher);
int		ft_think(t_philo *philosopher);
int		ft_print(t_philo *philosopher, char message);
int		ft_usleep(t_philo *philosopher, long target_time_length);
int		ft_has_philo_died(t_philo_pack	*philo_pack, int i);
long	ft_compute_time_to_think(t_philo *philosopher);
long	ft_compute_time_to_think_odd(int id, int count_meals,
			t_philo *philosopher);
long	ft_get_time_diff(long start);
long	ft_get_time(void);
long	ft_time_to_think_odd_above_3(t_philo *philosopher);
long	ft_max(long a, long b);
void	ft_end(void);
void	ft_update_end(t_philo_pack *philo_pack, int i);
int		ft_count_eaten_target_reached(t_philo philosopher);

#endif
