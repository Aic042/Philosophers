/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:56:42 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/19 13:57:09 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	three_philos(t_philo *p)
{
	pthread_mutex_lock(&p->config->take_forks);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->config->take_forks);
		return (0);
	}
	pthread_mutex_lock(&p->fork_l->fork);
	pthread_mutex_lock(&p->fork_r->fork);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->fork_r->fork);
		pthread_mutex_unlock(&p->fork_l->fork);
		pthread_mutex_unlock(&p->config->take_forks);
		return (0);
	}
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	pthread_mutex_unlock(&p->config->take_forks);
	return (1);
}

void	philo_eat_helper(t_philo *p)
{
	pthread_mutex_lock(&p->config->death_mutex);
	p->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&p->config->death_mutex);
	sleep_function(p, p->config->time_to_eat);
	pthread_mutex_unlock(&p->fork_r->fork);
	pthread_mutex_unlock(&p->fork_l->fork);
	pthread_mutex_lock(&p->config->meals);
}
