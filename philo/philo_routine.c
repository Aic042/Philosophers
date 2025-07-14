/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/14 18:45:11 by root             ###   ########.fr       */
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


void philo_think(t_philo *p)
{
	print_status(p, "is thinking");
	usleep(p->config->time_to_eat * 1000);
	p->is_thinking = 1;
	p->is_Sleeping = 0;
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
	pthread_mutex_lock(&p->death_mutex);
	if (p->unalived == 0)
	{
		p->unalived = 1;
		print_status(p, "has died");
		p->config->exit = 1;
	}
	pthread_mutex_unlock(&p->death_mutex);
}

void	fork_taker(t_philo *p)
{
	if (p->id % 2 == 1)
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


void *routine(void *arg)
{
	t_philo *p = (t_philo *)arg;
	while (1)
	{
		if (p->config->exit)
			break;

		fork_taker(p);
		philo_feeder(p);
		drop_forks(p);

		if (p->config->exit)
			break;

		eepy_philo(p);
		if (p->config->exit)
			break;

		philo_think(p);

		if (p->config->number_of_times_each_philosopher_must_eat > 0 &&
			p->times_ate >= p->config->number_of_times_each_philosopher_must_eat)
			break;
	}
	return NULL;
}

void *monitor(void *arg) // Added monitor function
{
	    t_philo *philos = (t_philo *)arg;
    int i;
    long now;

    while (1)
    {
        i = 0;
        while (i < philos[0].config->philo_num)
        {
            pthread_mutex_lock(&philos[i].death_mutex);
            now = get_time_ms();
            if (!philos[i].unalived &&
                now - philos[i].last_meal_time > philos[i].config->time_to_die)
            {
                philo_die(&philos[i]);
                pthread_mutex_unlock(&philos[i].death_mutex);
                return NULL;
            }
            pthread_mutex_unlock(&philos[i].death_mutex);
            i++;
        }
        usleep(1000); // check every 1ms
    }
    return NULL;
}


// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }
