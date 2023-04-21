/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:58 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/21 18:18:35 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *ft_rotine_philos(void *p)
{
    t_philo *ph;
    ph = (t_philo *)p;
    if(ph->id % 2 == 0)
        usleep(ph->args->val_time_to_eat * 1000);
    while (!ph->args->is_dead)
    {
        pthread_mutex_lock(&ph->fork);
        printf("%lld %d has taken a fork\n",ft_get_timestamp_in_ms() - ph->args->start_eating ,ph->id);
        pthread_mutex_lock(&ph->next->fork);

        pthread_mutex_lock(&ph->args->m_display);
        printf("%lld %d has taken a fork\n",ft_get_timestamp_in_ms() - ph->args->start_eating ,ph->id);
        pthread_mutex_unlock(&ph->args->m_display);

        pthread_mutex_lock(&ph->args->m_display);
        printf("%lld %d is eating\n",ft_get_timestamp_in_ms() - ph->args->start_eating,ph->id);
        pthread_mutex_unlock(&ph->args->m_display);

        pthread_mutex_lock(&ph->args->m_eat);
        ph->last_eat =  ft_get_timestamp_in_ms();
        ph->nbr_eat++;
        if(ph->nbr_eat == ph->args->nbr_times_each_philo_must_eat)
            ph->args->meals++;
        pthread_mutex_unlock(&ph->args->m_eat);

        // usleep(ph->args->val_time_to_eat * 1000);
        ft_my_usleep(ft_get_timestamp_in_ms(),ph->args->val_time_to_eat);

        pthread_mutex_unlock(&ph->fork);
        pthread_mutex_unlock(&ph->next->fork);

        pthread_mutex_lock(&ph->args->m_display);
        printf("%lld %d is sleeping\n",ft_get_timestamp_in_ms() - ph->args->start_eating,ph->id);
        pthread_mutex_unlock(&ph->args->m_display);

        // usleep(ph->args->val_time_to_sleep * 1000);
        ft_my_usleep(ft_get_timestamp_in_ms(),ph->args->val_time_to_sleep);

        pthread_mutex_lock(&ph->args->m_display);
        printf("%lld %d is thinking\n",ft_get_timestamp_in_ms() - ph->args->start_eating,ph->id);
        pthread_mutex_unlock(&ph->args->m_display);
    }
    return(NULL);
}
void ft_my_usleep(long long time, int sleep)
{
    while(ft_get_timestamp_in_ms() - time < sleep)
        usleep(1);
    // uint64_t begin;
    // uint64_t  diff_time;
    //  begin = ft_get_timestamp_in_ms() * 1000;
    // while (1)
    // {
    //     diff_time = v_sleep_time - (ft_get_timestamp_in_ms() * 1000 - begin);
    //     if(diff_time > (uint64_t) v_sleep_time)
    //         return;
    //     if(diff_time < 200)
    //     {
    //         usleep(diff_time);
    //         return;
    //     }
    //     usleep(200);
    // }
}

void ft_free(t_philo **ph,t_philo_rules *rules)
{
    t_philo *next;
    t_philo *head;
    int i;
    head = *ph;
    i = 1;
    while (i <= head->args->nbr_philo)
    {
        next = head->next;
        pthread_mutex_destroy(&head->fork);
        free(head);
        head = NULL;
        if(next)
            head = next;
        i++;
    }
        pthread_mutex_destroy(&rules->m_dead);
}