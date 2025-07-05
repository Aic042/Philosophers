/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/04 07:56:31 by root             ###   ########.fr       */
=======
/*   Updated: 2025/07/04 13:28:36 by aingunza         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
}

void philo_die(t_philo *p)
{
    long now = get_time_ms();
    if ((now - p->config->last_meal_time) > p->config->time_to_die)
    {
        long timestamp = now - p->config->start_time;
        printf("%ld | Philo %d died\n", timestamp, p->id);
        exit(1); // or set a global flag
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
<<<<<<< HEAD
	int i;
	i = 0;
	while (1)
	{
		if (p->config->number_of_times_each_philosopher_must_eat && p->config->number_of_times_each_philosopher_must_eat > 0)
			if (i < p->config->number_of_times_each_philosopher_must_eat)
				break;
=======
	if (is_pair(p->config->philo_num))
	{
		printf("is pair\n");
		//los pares toman los tenedores de izuierda y derecha, los impares 
	}
	else
		printf("isn't pair\n");
		//los impares toman los tenedores de la  derecha y la izquierda;
	while (p->times_ate < 10)
	{
>>>>>>> refs/remotes/origin/main
		philo_feeder(p);
		eepy_philo(p);
		philo_think(p);
		philo_die(p);
		i++;
	}
	return NULL;
}

// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }