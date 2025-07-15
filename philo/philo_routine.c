/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:19 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/15 12:31:44 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_taker(t_philo *p)
{
	if (p->id % 2 == 1)
	{
		pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
		// print_status(p, "has taken a R_fork");
		pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
		// print_status(p, "has taken a L_fork");
	}
	else
	{
		pthread_mutex_lock(&p->config->forks[p->left_fork_id].fork);
		// print_status(p, "has taken a R_fork");
		pthread_mutex_lock(&p->config->forks[p->right_fork_id].fork);
		// print_status(p, "has taken a L_fork");
	}
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->config->forks[p->left_fork_id].fork);
	pthread_mutex_unlock(&p->config->forks[p->right_fork_id].fork);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		if (p->config->exit)
			break ;
		fork_taker(p);
		philo_feeder(p);
		drop_forks(p);
		if (p->config->exit)
			break ;
		eepy_philo(p);
		if (p->config->exit)
			break ;
		philo_think(p);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philos;
	int		i;
	long	now;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philos[0].config->philo_num)
		{
			pthread_mutex_lock(&philos[i].death_mutex);
			now = get_time_ms();
			if (!philos[i].unalived && now - philos[i].last_meal_time
				> philos[i].config->time_to_die)
			{
				philo_die(&philos[i]);
				pthread_mutex_unlock(&philos[i].death_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].death_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
