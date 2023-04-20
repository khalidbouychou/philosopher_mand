/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:00:07 by khbouych          #+#    #+#             */
/*   Updated: 2023/04/20 15:04:11 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*ft_addnew(t_philo_rules *rules)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (0);
	new->args = rules;
	new->next = NULL;
	return (new);
}

t_philo	*ft_addlist(t_philo *philo, t_philo *new)
{
	t_philo	*last;

	if (!philo)
	{
        philo = new;
		philo->next = new;
		return (philo);
	}
	last = philo;
    while(last->next != philo)
        last = last->next;
	last->next = new;
	new->next = philo;
	return (philo);
}