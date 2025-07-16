/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/16 08:33:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die_checker(t_philo *p)
{
	int	dead_philo;

	pthread_mutex_lock(&p->death_mutex);
	if (p->unalived)
		dead_philo = 1;
	else
		dead_philo = 0;
	pthread_mutex_unlock(&p->death_mutex);
	return (dead_philo);
}

int check_one_philo(t_philo *p)
{
	if (p->config->philo_num == 1)
	{
		print_status(p, "has taken a fork");
		sleep_function(p, p->config->time_to_die);
		philo_die(p);  // <--- Añade esto
		return (1);
	}
	return (0);
}

int	take_forks(t_philo *p)
{
	pthread_mutex_lock(&p->config->take_forks);

	if (die_checker(p))
	{
		pthread_mutex_unlock(&p->config->take_forks);
		return (0);
	}
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
		print_status(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
		print_status(p, "has taken a fork");
	}

	pthread_mutex_unlock(&p->config->take_forks);
	return (1);
}

void sleep_function(t_philo *p, int time)
{
	long	start_time;
	long	current_time;
	
	start_time = get_time_ms();
	while (!get_exit(p->config))
	{
		current_time = get_time_ms();
		if (current_time - start_time >= time)
			return;
		if (current_time - p->last_meal_time >= p->config->time_to_die)
		{
			philo_die(p);
			return;
		}
		usleep(50); // para no quemar la CPU
	}
	
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->config->forks[p->left_fork_id].fork);
	pthread_mutex_unlock(&p->config->forks[p->right_fork_id].fork);
}

void    *routine(void *arg)
{
    t_philo *p = (t_philo *)arg;

    if (check_one_philo(p)) // <-- solución aquí
        return NULL;
    // Sleep inicial para evitar colisiones
    if ((p->config->philo_num % 2 == 0 && p->id % 2 != 0)
        || (p->config->philo_num % 2 != 0 && p->id % 2 == 0))
        usleep(100);
	// if (p->id % 2 == 0)
    // 	usleep(100);  // Give odd numbers a head start
	init_sleep(p);
    while (1)
    {
		if (get_exit(p->config))
			break;

        take_forks(p);
        philo_feeder(p);
        drop_forks(p);
        if (get_exit(p->config))
            break;
        eepy_philo(p);
        if (get_exit(p->config))
            break;
        philo_think(p);
    }
    return (NULL);
}

void *monitor(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    int i;
    long now;

    while (!philos[0].config->exit)
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
        usleep(500);
    }
    return NULL;
}

