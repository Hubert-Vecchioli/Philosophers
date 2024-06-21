/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/21 17:00:08 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char err)
{
	if (err == 'i')
		ft_putstr_fd("Error: Wrong arg number\n", 2);
	exit(0);
}
void	ft_free(t_game *game)
{