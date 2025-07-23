/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:25:32 by root              #+#    #+#             */
/*   Updated: 2025/07/23 12:40:01 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_function(t_philo *p, int time)
{
	long	start_time;
	long	current_time;

	start_time = get_time_ms();
	while (1)
	{
		current_time = get_time_ms();
		if (current_time - start_time >= time)
			return ;
		if (current_time - p->last_meal_time >= p->config->time_to_die)
		{
			philo_die(p);
			return ;
		}
		usleep(150);
	}
}

void	init_sleep(t_philo *p)
{
	if (p->id % 2 == 0)
		usleep(150);
	else if (p->config->philo_num % 2 != 0)
		usleep(100);
	usleep(1000);
}

int	all_philos_ate_enough(t_philo *p)
{
	int	i;
	int	finished;

	finished = 1;
	i = 0;
	pthread_mutex_lock(&p->config->meals);
	while (i < p->config->philo_num)
	{
		if (p[i].times_ate < p->config->num_of_times_each_philo_must_eat)
		{
			finished = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&p->config->meals);
	return (finished);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (check_one_philo(p))
		return (NULL);
	init_sleep(p);
	joint_actions(p);
	printf("Philo %d has finished eating %d times.\n", p->id, p->times_ate);
	return (NULL);
}

void	meal(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->config->philo_num)
	{
		p[i].last_meal_time = p->config->start_time;
		pthread_create(&p[i].threads, NULL, &routine, &p[i]);
		usleep(1);
		i++;
	}
	i = 0;
	while (i < p->config->philo_num)
	{
		pthread_join(p[i].threads, NULL);
		i++;
	}
}
