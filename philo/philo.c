/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:08:15 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/21 17:22:15 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac , char **ag)
{
    t_philo_rules *arg_philo;
    t_philo *philo;

    philo = NULL;
    if(ac != 5 && ac != 6)
        return(printf("Error - incorrect number of args! \n"),0);
    if (!(atoi(ag[1]) >= 1 && atoi(ag[1]) <= 200))
       return (printf("Error - incorrect number of philosophers!\n"), 0);
    arg_philo = ft_init_philo_rules(arg_philo, ag);
    philo = ft_create_philos(philo, arg_philo);
    // if(!ft_check_args(ag) || !arg_philo || !philo)
    //     return(printf("Error - in args\n"),0);
    // if(!arg_philo)
    //     return(printf("Error - in args\n"),0);
    ft_create_philo_to_thread(philo,arg_philo);
    // ft_free(&philo, arg_philo);
}

