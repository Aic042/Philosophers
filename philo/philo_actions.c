/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:30:15 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/16 08:32:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eepy_philo(t_philo *p)
{
	print_status(p, "is sleeping");
    sleep_function(p, p->config->time_to_sleep);
	p->is_sleeping = 1;
	p->is_eating = 0;
}

void	philo_think(t_philo *p)
{
	print_status(p, "is thinking");
	sleep_function(p, 50);
	p->is_thinking = 1;
	p->is_sleeping = 0;
}

void philo_feeder(t_philo *p)
{
    pthread_mutex_lock(&p->config->meals);

    if (p->times_ate == p->config->number_of_times_each_philosopher_must_eat)
    {
        pthread_mutex_unlock(&p->config->meals);
        return; // ya comió suficiente, no come más
    }

    p->last_meal_time = get_time_ms();
    print_status(p, "is eating");
    sleep_function(p, p->config->time_to_eat);
    p->times_ate++;

    // Si acaba de alcanzar el límite de comidas:
    if (p->times_ate == p->config->number_of_times_each_philosopher_must_eat)
        p->config->satisfied_philos++;

    pthread_mutex_unlock(&p->config->meals);

    p->is_eating = 1;
    p->is_thinking = 0;
}

void	philo_die(t_philo *p)
{
	pthread_mutex_lock(&p->death_mutex);
	if (p->unalived == 0)
	{
		p->unalived = 1;
		print_status(p, "has died");
		set_exit(p->config, 1);
	}
	pthread_mutex_unlock(&p->death_mutex);
}