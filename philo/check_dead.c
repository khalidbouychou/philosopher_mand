/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:15:20 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/22 00:36:42 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_check_dead_case(t_philo *ph)
{
    t_philo *cur;
    cur = ph;
    while (1)
    {
        usleep(1000);
        while (cur)
        {
            pthread_mutex_lock(&ph->args->m_eat);
            if (ft_get_timestamp_in_ms() - cur->last_eat > cur->args->val_time_to_die)
            {
                pthread_mutex_lock(&cur->args->m_dead);
                cur->args->is_dead = 1;
                pthread_mutex_unlock(&cur->args->m_dead);
                ft_output(ft_get_timestamp_in_ms() ,cur,"died");
                return;
            }
            // pthread_mutex_lock(&cur->args->m_meals);
            // if(cur->args->meals == cur->args->nbr_philo)
            // {
            //     pthread_mutex_lock(&cur->args->m_dead);
            //     cur->args->is_dead = 1;
            //     pthread_mutex_unlock(&cur->args->m_dead);
            //     return;
            // }
            // pthread_mutex_unlock(&cur->args->m_meals);
            pthread_mutex_unlock(&ph->args->m_eat);
            cur = cur->next;
            if(cur == ph)
                break;
        }
    }
}
