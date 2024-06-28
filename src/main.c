/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/28 10:59:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_pack	philo_pack;

	if (ac < 5 || ac > 6)
		return (ft_error('i'), 0);
	ft_init_pack(ac, av, &philo_pack);
	ft_init_philos(&philo_pack);
	ft_init_threads(&philo_pack);
	ft_free(&philo_pack);
	return (0);
}
