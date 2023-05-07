/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:51:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/06 11:27:27 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	ft_skipp(int *i, const char *p_str, int *sign)
{
	while ((p_str[*i] >= 9 && p_str[*i] <= 13) || p_str[*i] == ' ')
		(*i)++;
	if (p_str[*i] == '-' || p_str[*i] == '+')
	{
		if (p_str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int ft_check_number(char *ag)
{
	int i;
	i = 0;
	while (ag[i])
	{
		if(!ft_isdigit(ag[i]) && ag[i] != '+' && ag[i]!= '-')
			return(0);
		i++;
	}
	return(1);
}
int ft_check(char **ag , int ac)
{
	int i;
	i = 1;
	if (!(atoi(ag[1]) >= 1 && atoi(ag[1]) <= 200) || (ac != 5 && ac != 6))
       return (0);
	while (i < ac)
	{
		if(!ft_atoi(ag[i]) || ft_atoi(ag[i]) < 1)
			return(0);
		if(!ag[i] || !ft_check_number(ag[i++]))
			return(0);
	}
	return(1);
}
int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;
	char		*p_str;
	long long	prev_res;

	p_str = (char *)str;
	i = 0;
	res = 0;
	sign = 1;
	ft_skipp(&i, &str[i], &sign);
	while (ft_isdigit(p_str[i]))
	{
		prev_res = res;
		res = res * 10 + p_str[i] - '0';
		if ((res / 10) != prev_res)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (sign * res);
}