/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:08:15 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/24 17:27:10 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac , char **ag)
{
    t_philo_rules *arg_philo;
    t_philo *philo;

    philo = NULL;
    if(!ft_check(ag,ac))
        return(printf("error\n"),0);
    else
        printf("nice\n");
    // arg_philo = ft_init_philo_rules(arg_philo, ag);
    // philo = ft_create_philos(philo, arg_philo);
    // if(!ft_check_args(ag) || !arg_philo || !philo)
    //     return(printf("Error - in args\n"),0);
    // if(!arg_philo)
    //     return(printf("Error - in args\n"),0);
    // ft_create_philo_to_thread(philo,arg_philo);
    // ft_free(&philo, arg_philo);
}

