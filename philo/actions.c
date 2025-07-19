/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:40:28 by root              #+#    #+#             */
/*   Updated: 2025/07/19 13:57:00 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eepy_philo(t_philo *p)
{
	if (die_checker(p))
		return ;
	print_status(p, "\001\033[1;32m\002is sleeping\005\033[0m\002");
	sleep_function(p, p->config->time_to_sleep);
	p->is_sleeping = 0;
	p->is_thinking = 1;
}

void	philo_think(t_philo *p)
{
	print_status(p, "\001\033[1;93m\002is thinking\001\033[0m\002");
	p->is_thinking = 0;
	p->is_eating = 1;
}

void	philo_die(t_philo *p)
{
	pthread_mutex_lock(&p->config->death_mutex);
	if (p->unalived == 1)
	{
		p->unalived = 0;
		print_status(p, "\001\033[1;45m\002died\001\033[0m\002");
		set_exit(p->config, 1);
	}
	pthread_mutex_unlock(&p->config->death_mutex);
}

int	grab_forks(t_philo *p)
{
	pthread_mutex_lock(&p->fork_r->fork);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->fork_r->fork);
		return (0);
	}
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	pthread_mutex_lock(&p->fork_l->fork);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->fork_l->fork);
		pthread_mutex_unlock(&p->fork_r->fork);
		return (0);
	}
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	return (1);
}

void	philo_eat(t_philo *p)
{
	if (die_checker(p) || time_over(p))
		return ;
	if (p->config->philo_num == 3)
	{
		if (!three_philos(p))
			return ;
	}
	else
	{
		if (!grab_forks(p))
			return ;
	}
	print_status(p, "\001\033[1;31m\002is eating\001\033[0m\002");
	philo_eat_helper(p);
	if (p->config->num_of_times_each_philo_must_eat > 0 && p->times_ate
		>= p->config->num_of_times_each_philo_must_eat)
	{
		pthread_mutex_unlock(&p->config->meals);
		return ;
	}
	p->times_ate++;
	pthread_mutex_unlock(&p->config->meals);
	p->is_eating = 0;
	p->is_sleeping = 1;
}
