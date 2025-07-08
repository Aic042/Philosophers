/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/08 12:39:04 by aingunza         ###   ########.fr       */
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
	p->last_meal_time = get_time_ms();
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

void	fork_taker(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
		print_status(p, "has taken a R_fork");
		pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
		print_status(p, "has taken a L_fork");
	}
    else
    {
        pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
        print_status(p, "has taken a R_fork");
        pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
        print_status(p, "has taken a L_fork");
    }
}

void	drop_forks(t_philo * p)
{
	pthread_mutex_unlock(&p->config->forks[p->left_fork_id].fork);
	pthread_mutex_unlock(&p->config->forks[p->right_fork_id].fork);
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

    while (1)
    {
        philo_die(p);

        fork_taker(p);
        philo_feeder(p);
        drop_forks(p);

        philo_die(p);
        eepy_philo(p);

        philo_die(p);
        philo_think(p);

        if (p->config->number_of_times_each_philosopher_must_eat > 0 &&
            p->times_ate >= p->config->number_of_times_each_philosopher_must_eat)
            break;
    }
    return NULL;
}


// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }