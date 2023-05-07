/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:08:15 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/07 15:24:33 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void l()
{
    system("leaks philo");
}
int main(int ac , char **ag)
{
    t_philo_rules *arg_philo = NULL;
    t_philo *philo;
    // atexit(l);
    philo = NULL;
    if(!ft_check(ag,ac))
        return(printf("\t [ Error ]\n"),0);
    arg_philo = ft_init_philo_rules(arg_philo, ag);
    philo = ft_create_philos(philo, arg_philo);
    if(!arg_philo || !philo)
        return(printf("\t[ Error ]\n"),0);
    ft_create_philo_to_thread(philo,arg_philo);
    ft_free(&philo, arg_philo);
}

