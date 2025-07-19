/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitdeath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:40:46 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/19 13:51:02 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_exit(t_config *c)
{
	int	res;

	pthread_mutex_lock(&c->exit_mutex);
	res = c->exit;
	pthread_mutex_unlock(&c->exit_mutex);
	return (res);
}

void	set_exit(t_config *c, int value)
{
	pthread_mutex_lock(&c->exit_mutex);
	c->exit = value;
	pthread_mutex_unlock(&c->exit_mutex);
}

int	die_checker(t_philo *p)
{
	int	dead_philo;

	pthread_mutex_lock(&p->config->death_mutex);
	dead_philo = (p->unalived == 0);
	pthread_mutex_unlock(&p->config->death_mutex);
	return (dead_philo);
}

int	check_one_philo(t_philo *p)
{
	if (p->config->philo_num == 1)
	{
		print_status(p, "has taken a fork");
		sleep_function(p, p->config->time_to_die);
		philo_die(p);
		return (1);
	}
	return (0);
}

void	joint_actions(t_philo *p)
{
	while (1)
	{
		if (get_exit(p->config))
			break ;
		if (time_over(p))
		{
			philo_die(p);
			break ;
		}
		if (die_checker(p))
			break ;
		if (p->config->num_of_times_each_philo_must_eat > 0
			&& all_philos_ate_enough(p - (p->id - 1)))
		{
			set_exit(p->config, 1);
			break ;
		}
		if (p->is_thinking == 1)
			philo_think(p);
		if (p->is_eating == 1 && !die_checker(p))
			philo_eat(p);
		if (p->is_sleeping == 1 && !die_checker(p))
			eepy_philo(p);
	}
}
