/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/07 14:19:59 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eepy_philo(t_philo *p)
{
	print_status(p, "is sleeping");
	usleep(p->config->time_to_sleep * 1000);
	p->is_Sleeping = 1;
	p->is_eating = 0;
}

void philo_feeder(t_philo *p)
{
	print_status(p, "is eating");
	p->last_meal_time = get_time_ms();
	usleep(p->config->time_to_eat * 1000);
	(p->times_ate)++;
	p->is_eating = 1;
	p->is_thinking = 0;
	p->last_meal_time = timestamp
}

void philo_die(t_philo *p)
{
	long now = get_time_ms();
	if ((now - p->last_meal_time) > p->config->time_to_die)
	{
		long timestamp = now - p->config->start_time;
		printf("%ld Philo %d died\n", timestamp, p->id);
		p->unalived = 1; // or set a global flag
		
	}
}

void philo_think(t_philo *p)
{
	print_status(p, "is thinking");
	usleep(p->config->time_to_eat * 1000);
	p->is_thinking = 1;
	p->is_Sleeping = 0;
}

void *routine(void *arg)
{
	t_philo *p = (t_philo *)arg;
	p->times_ate = 0;
	int i;
	i = 0;
	while (1)
	{
		if (p->config->number_of_times_each_philosopher_must_eat > 0 &&
			p->times_ate >= p->config->number_of_times_each_philosopher_must_eat)
			break;
		if (p->unalived == 1)
			break;
		// philo_die(p);               // revisar justo al comenzar

		philo_feeder(p);
		// philo_die(p);               // por si te mueres durante el sleep

		eepy_philo(p);
		// philo_die(p);               // por si te mueres mientras duermes

		philo_think(p);
		// philo_die(p);               // por si te mueres pensando
		i++;
	}
	return NULL;
}

// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }