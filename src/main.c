/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/24 17:58:31 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_pack	philo_pack;

	if (ac < 5 || ac > 6)
		return  ft_exit('i');
	ft_parse(ac, av, &philo_pack);
	ft_init_philos(&philo_pack);
	
	return (ft_free(&philo_pack), 0);
}
