/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:30:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/21 18:27:59 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long long ft_get_timestamp_in_ms()
{
    struct timeval today_time;
    long long  time;
    gettimeofday(&today_time, NULL);
    time =(today_time.tv_sec * 1000) + (today_time.tv_usec / 1000);
    return (time);
}
t_philo_rules *ft_init_philo_rules(t_philo_rules *arg_philo , char **args)
{
    arg_philo = malloc (sizeof(t_philo_rules));
    if(!arg_philo)
        return NULL;
    if(!ft_atoi(args[1]))
        return (0);
    if(args[5])
    {
        arg_philo->nbr_times_each_philo_must_eat =ft_atoi(args[5]);
        if(!arg_philo->nbr_times_each_philo_must_eat)
            return(0);
    }
    else
    arg_philo->nbr_times_each_philo_must_eat = -1;
    arg_philo->nbr_philo = ft_atoi(args[1]);
    arg_philo->val_time_to_die = ft_atoi(args[2]);
    arg_philo->val_time_to_eat = ft_atoi(args[3]);
    arg_philo->val_time_to_sleep = ft_atoi(args[4]);
    arg_philo->is_dead = 0;
    arg_philo->meals = 0;
    return(arg_philo);
}
t_philo *ft_create_philos(t_philo *ph, t_philo_rules *rules)
{
    int i;
    t_philo *tmp;
    i = 0;
    while (i < rules->nbr_philo)
    {
        tmp = ft_addnew(rules);
        tmp->id = (i + 1);
        ph = ft_addlist(ph,tmp);
        i++;
    }
    // tmp = ph;
    // while(tmp)
    // {
    //     printf("%d\n",tmp->id);
    //     tmp = tmp->next;
    //     if(tmp->id == 1)
    //         break;
    // }
    return (ph);
}



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
                cur->args->is_dead = 1;
                pthread_mutex_lock(&cur->args->m_display);
                printf("%lld %d died\n",ft_get_timestamp_in_ms() - cur->args->start_eating , cur->id);
               return;
            }
            else if(cur->args->meals == cur->args->nbr_times_each_philo_must_eat)
            {
                cur->args->is_dead = 1;
                return;
            }
            pthread_mutex_unlock(&ph->args->m_eat);
            cur = cur->next;
            if(cur == ph)
                break;
        }
    }
}
void ft_create_philo_to_thread(t_philo *ph, t_philo_rules *rules)
{
    int i;
    int nbr_philo;
    t_philo *cur;
    cur = ph;
    while (cur)
    {
        pthread_mutex_init(&cur->fork,NULL);
        cur = cur->next;
        if(cur == ph)
            break;
    }
    cur = ph;
    rules->start_eating = ft_get_timestamp_in_ms();
    pthread_mutex_init(&rules->m_eat,NULL);
    pthread_mutex_init(&rules->m_dead,NULL);
    pthread_mutex_init(&rules->m_display,NULL);
    // ft_my_usleep(1000);
    while(cur)
    {
        cur->last_eat = rules->start_eating;
        pthread_create(&cur->thread_id,NULL,ft_rotine_philos,cur);
        cur = cur->next;
        if(cur == ph)
            break;
    }
    ft_check_dead_case(ph);
    // while(cur)
    // {
    //     pthread_join(cur->thread_id,NULL);
    //     cur = cur->next;
    //     if(cur == ph)
    //         break;
    // }
}

