/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_and_parse_inputs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:55 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/24 17:42:45 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
static int	ft_atoi(char *str)
{
	int		i;
	int		j;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error('d'), 0);
		res = res * 10 + str[i++] - '0';
		j++;
	}
	if ((sign * res) > 2147483647 || (sign * res) < 0 || j == 0)
		return (ft_error('d'), 0);
	return (sign * res);
}

void	ft_parse(int ac, char **av, t_philo_pack *philo_pack)
{
	int	i;
	
	i = 1;
	philo_pack->count_philo = ft_atoi(av[1]);
	if (philo_pack->count_philo == 0)
		ft_error('0');
	philo_pack->time_to_die = ft_atoi(av[2]);
	philo_pack->time_to_eat = ft_atoi(av[3]);
	philo_pack->time_to_sleep = ft_atoi(av[4]);
	philo_pack->max_eat_philo_must_eat = -1;
	if (ac == 6)
	{
		philo_pack->max_eat_philo_must_eat = ft_atoi(av[1]);
	}
	philo_pack->start_time = 0;
}
