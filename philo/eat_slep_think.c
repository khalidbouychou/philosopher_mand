/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_slep_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:04:24 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/22 00:05:13 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_philo *ph)
{
    pthread_mutex_lock(&ph->fork);
    ft_output(ft_get_timestamp_in_ms() ,ph,"has taken a fork");
    pthread_mutex_lock(&ph->next->fork);
    ft_output(ft_get_timestamp_in_ms() ,ph,"has taken a fork");
    ft_output(ft_get_timestamp_in_ms() ,ph,"is eating");
    ft_my_usleep(ft_get_timestamp_in_ms(),ph->args->val_time_to_eat);
    pthread_mutex_lock(&ph->args->m_eat);
    ph->last_eat =  ft_get_timestamp_in_ms();
    ph->nbr_eat++;
    if(ph->nbr_eat == ph->args->nbr_times_each_philo_must_eat)
        ph->args->meals++;
    pthread_mutex_unlock(&ph->args->m_eat);
    pthread_mutex_unlock(&ph->fork);
    pthread_mutex_unlock(&ph->next->fork);
}
void ft_slep(t_philo *ph)
{
    ft_output(ft_get_timestamp_in_ms() ,ph,"is sleeping");
    ft_my_usleep(ft_get_timestamp_in_ms(),ph->args->val_time_to_sleep);
}
void ft_think(t_philo *ph)
{
    ft_output(ft_get_timestamp_in_ms() ,ph,"is thinking");
}
