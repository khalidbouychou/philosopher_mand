/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:08:15 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/15 14:08:11 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_philo_rules	*arg_philo;
	t_philo			*philo;

	arg_philo = NULL;
	philo = NULL;
	if (!ft_check(ag, ac))
		return (printf("\t [ Error ]\n"), 0);
	arg_philo = ft_init_philo_rules(arg_philo, ag);
	philo = ft_create_philos(philo, arg_philo);
	if (!arg_philo || !philo)
		return (printf("\t[ Error ]\n"), 0);
	ft_create_philo_to_thread(philo, arg_philo);
	if(ft_check_dead_case(philo))
		return (0);
	ft_free(&philo, arg_philo);
}
