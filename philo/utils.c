/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:06:24 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/22 00:20:19 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_my_usleep(long long time, int sleep)
{
    while(ft_get_timestamp_in_ms() - time < sleep)
        usleep(1);
}
void ft_output(long long t , t_philo *ph,char *msg)
{
    pthread_mutex_lock(&ph->args->m_display);
    printf("%lld %d %s\n",(t - ph->args->start_eating) , ph->id,msg);
    pthread_mutex_unlock(&ph->args->m_display);
}
void ft_mutex_init(t_philo_rules *rules)
{
    pthread_mutex_init(&rules->m_eat,NULL);
    pthread_mutex_init(&rules->m_dead,NULL);
    pthread_mutex_init(&rules->m_display,NULL);
    pthread_mutex_init(&rules->m_meals,NULL);
}
long long ft_get_timestamp_in_ms()
{
    struct timeval today_time;
    long long  time;
    gettimeofday(&today_time, NULL);
    time =(today_time.tv_sec * 1000) + (today_time.tv_usec / 1000);
    return (time);
}
void ft_detach(t_philo *ph)
{
    t_philo *cur;
    cur = ph;
    while (cur)
    {
        pthread_detach(cur->thread_id);
        cur = cur->next;
        if(cur == ph)
            return;
    }
}

