/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:15:20 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/07 13:24:38 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_count_nbr_eat(t_philo *ph)
{
    t_philo *cur;
    cur = ph;
    while (cur)
    {
        if(cur->nbr_eat == cur->args->nbr_times_each_philo_must_eat)
            return 1;
        cur = cur->next;
        if(cur == ph)
            break;
    }
    return 0;
}
void ft_check_dead_case(t_philo *ph)
{
    t_philo *cur;
    cur = ph;
    while (1)
    {
           usleep(300);
        while (cur)
        {
            pthread_mutex_lock(&ph->args->m_eat);
            if (ft_get_timestamp_in_ms() - cur->last_eat > cur->args->val_time_to_die)
            {
                pthread_mutex_lock(&cur->args->m_dead);
                cur->args->is_dead = 1;
                ft_output(ft_get_timestamp_in_ms() ,cur," died");
                return;
            }
            pthread_mutex_lock(&cur->args->m_meals);
            if(ft_count_nbr_eat(cur))
            {
                pthread_mutex_lock(&cur->args->m_dead);
                cur->args->is_dead = 1;
                return ;
            }
            pthread_mutex_unlock(&cur->args->m_meals);
            pthread_mutex_unlock(&ph->args->m_eat);
            cur = cur->next;
            if(cur == ph)
                break;
        }
    }
}
