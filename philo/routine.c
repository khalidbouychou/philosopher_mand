/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:58 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/17 12:44:34 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_rotine_philos(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	if (ph->id % 2 == 0)
		usleep(ph->args->val_time_to_eat * 1000);
	while (1)
	{
		ft_eat(ph);
		ft_slep(ph);
		ft_think(ph);
	}
	return (NULL);
}
