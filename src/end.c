/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/24 16:05:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char err)
{
	if (err == 'i')
		ft_putstr_fd("Error: Wrong arg number\n", 2);	
	if (err == 'd')
		ft_putstr_fd("Error: inputs are not valid digits\n", 2);
	if (err == '0')
		ft_putstr_fd("Error: no philosopher in the input\n", 2);
	if (err == 'm')
		ft_putstr_fd("Error: Malloc failed\n", 2);
	if (err == 'x')
		ft_putstr_fd("Error: Mutex failed\n", 2);
	exit(0);
}
void	ft_free(t_philo_pack *philo_pack)
{
	// free les philos
}