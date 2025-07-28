/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:56:42 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/28 16:34:28 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	three_philos(t_philo *p)
{
	pthread_mutex_lock(&p->config->take_forks);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->config->take_forks);
		return (0);
	}
	pthread_mutex_lock(&p->fork_l->fork);
	pthread_mutex_lock(&p->fork_r->fork);
	if (die_checker(p) || time_over(p))
	{
		pthread_mutex_unlock(&p->fork_r->fork);
		pthread_mutex_unlock(&p->fork_l->fork);
		pthread_mutex_unlock(&p->config->take_forks);
		return (0);
	}
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	print_status(p, "\001\033[1;35m\002has taken a fork\001\033[0m\002");
	pthread_mutex_unlock(&p->config->take_forks);
	return (1);
}

void	philo_eat_helper(t_philo *p)
{
	pthread_mutex_lock(&p->config->last_meal_mutex);
	p->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&p->config->last_meal_mutex);
	sleep_function(p, p->config->time_to_eat);
	pthread_mutex_unlock(&p->fork_r->fork);
	pthread_mutex_unlock(&p->fork_l->fork);
	pthread_mutex_lock(&p->config->meals);
}

void	*monitor_routine(void *arg)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)arg;
	while (!get_exit(p->config))
	{
		i = 0;
		while (i < p->config->philo_num)
		{
			if (time_over(&p[i]))
			{
				philo_die(&p[i]);
				return (NULL);
			}
			if (p->config->num_of_times_each_philo_must_eat > 0
				&& all_philos_ate_enough(p))
			{
				set_exit(p->config, 1);
				return (NULL);
			}
			i++;
		}
		usleep(10);
	}
	return (NULL);
}
