/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:52:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/24 15:43:38 by khbouych         ###   ########.fr       */
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
    int track;
    int val_time_to_die;
    int val_time_to_eat;
    int val_time_to_sleep;
    int nbr_times_each_philo_must_eat;
    long start_eating;
    int is_dead;
    pthread_mutex_t m_dead;
    pthread_mutex_t m_meals;
    pthread_mutex_t m_eat;
    pthread_mutex_t m_display;
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

/*********utils**************/
int	ft_atoi(const char *str);
void ft_my_usleep(long long time, int sleep);
void ft_output(long long t , t_philo *ph,char *msg);
void ft_mutex_init(t_philo_rules *rules);
long long ft_get_timestamp_in_ms();
void ft_detach(t_philo *ph);
/****************************/
int ft_check(char **ag , int ac);
void ft_check_dead_case(t_philo *ph);
t_philo_rules *ft_init_philo_rules(t_philo_rules *arg_philo , char **args);
t_philo *ft_create_philos(t_philo *ph, t_philo_rules *rules);
void ft_create_philo_to_thread(t_philo *ph, t_philo_rules *rules);
/********list****************/
t_philo	*ft_addnew(t_philo_rules *rules);
t_philo	*ft_addlist(t_philo *philo, t_philo *new);
/*******rotine***************/
void ft_eat(t_philo *ph);
void ft_slep(t_philo *ph);
void ft_think(t_philo *ph);
void *ft_rotine_philos(void *p);
/********free****************/
void ft_free(t_philo **ph,t_philo_rules *rules);
#endif