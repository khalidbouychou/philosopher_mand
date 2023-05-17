/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:05:36 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/17 15:45:16 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo **ph, t_philo_rules *rules)
{
	(void)rules;
	t_philo	*next;
	t_philo	*head;
	int		i;

	head = *ph;
	i = 1;
	while (i <= head->args->nbr_philo)
	{
		next = head->next;
		pthread_mutex_destroy(&head->fork);
		head = NULL;
		free(head);
		if (next)
			head = next;
		i++;
	}
}
