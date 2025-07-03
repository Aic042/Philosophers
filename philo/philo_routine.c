/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/03 12:52:37 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eepy_philo(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is sleeping\n", timestamp, p->id);
	usleep(p->config->time_to_sleep * 1000);
}

void philo_feeder(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is eating\n", timestamp, p->id);
	p->config->last_meal_time = get_time_ms();
	usleep(p->config->time_to_eat * 1000);
	(p->times_ate)++;
	printf("times eaten: %d\n", p->times_ate);
}

void philo_die(t_philo *p)
{
	
	long timestamp = get_time_ms() - p->config->start_time;
	if (p->config->last_meal_time >= p->config->time_to_die)
	{
		printf("%ld | philo %d died", timestamp, p->id);
		exit (2);
	}
}

void philo_think(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is thinking\n", timestamp, p->id);
	usleep(p->config->time_to_eat * 1000);
}



void *routine(void *arg)
{
	t_philo *p = (t_philo *)arg;
	p->times_ate = 0;
	while (p->times_ate < 100)
	{
		eepy_philo(p);
		philo_feeder(p);
		philo_think(p);
	}
	return NULL;
}

// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }