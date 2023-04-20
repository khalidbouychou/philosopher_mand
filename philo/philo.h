/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:52:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/20 16:43:48 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

/****************************************/
typedef struct s_rules
{
    int nbr_philo;
    int val_time_to_die;
    int val_time_to_eat;
    int val_time_to_sleep;
    int nbr_times_each_philo_must_eat;
    long start_eating;
    int is_dead;
    pthread_mutex_t mutex;
}t_philo_rules;

typedef struct s_philo
{
    int id;
    int nbr_eat;
    long long last_eat;
    pthread_t thread_id;
    pthread_mutex_t fork;
    t_philo_rules *args;
    struct s_philo *next;
}t_philo;


/****************************************/
int ft_check_args(char **ar);
t_philo_rules *ft_init_philo_rules(t_philo_rules *arg_philo , char **args);
t_philo *ft_create_philos(t_philo *ph, t_philo_rules *rules);
int	ft_atoi(const char *str);
void ft_create_philo_to_thread(t_philo *ph, t_philo_rules *rules);
long long ft_get_timestamp_in_ms();
// lists
t_philo	*ft_addnew(t_philo_rules *rules);
t_philo	*ft_addlist(t_philo *philo, t_philo *new);
#endif