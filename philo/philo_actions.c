/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:30:15 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/15 12:30:38 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eepy_philo(t_philo *p)
{
	print_status(p, "is sleeping");
	usleep(p->config->time_to_sleep * 1000);
	p->is_sleeping = 1;
	p->is_eating = 0;
}

void	philo_think(t_philo *p)
{
	print_status(p, "is thinking");
	usleep(p->config->time_to_eat * 1000);
	p->is_thinking = 1;
	p->is_sleeping = 0;
}

void	philo_feeder(t_philo *p)
{
	print_status(p, "is eating");
	p->last_meal_time = get_time_ms();
	usleep(p->config->time_to_eat * 1000);
	(p->times_ate)++;
	p->is_eating = 1;
	p->is_thinking = 0;
	p->last_meal_time = get_time_ms();
}

void	philo_die(t_philo *p)
{
	pthread_mutex_lock(&p->death_mutex);
	if (p->unalived == 0)
	{
		p->unalived = 1;
		print_status(p, "has died");
		p->config->exit = 1;
	}
	pthread_mutex_unlock(&p->death_mutex);
}