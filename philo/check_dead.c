/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:15:20 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/17 15:43:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_count_nbr_eat(t_philo *ph)
{
	t_philo	*cur;

	cur = ph;
	while (cur)
	{
		if (cur->nbr_eat == cur->args->nbr_times_each_philo_must_eat)
			return (1);
		cur = cur->next;
		if (cur == ph)
			break ;
	}
	return (0);
}

int	ft_help(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->m_eat);
	if (ft_get_timestamp_in_ms() - ph->last_eat > ph->args->val_time_to_die)
	{
		ft_output(ft_get_timestamp_in_ms(), ph, " died");
		return (0);
	}
	pthread_mutex_lock(&ph->args->m_meals);
	if (ft_count_nbr_eat(ph))
		return (0);
	pthread_mutex_unlock(&ph->args->m_meals);
	pthread_mutex_unlock(&ph->args->m_eat);
	return (1);
}

int	ft_check_dead_case(t_philo *ph)
{
	t_philo	*cur;

	cur = ph;
	while (1)
	{
		while (cur)
		{
			usleep(300);
			if (!ft_help(cur))
				return (0);
			cur = cur->next;
			if (cur == ph)
				break ;
		}
	}
	return (1);
}
