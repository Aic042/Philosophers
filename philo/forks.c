/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:41:21 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/15 11:42:32 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *p, char *msg)
{
	long	timestamp;

	timestamp = get_time_ms() - p->config->start_time;
	pthread_mutex_lock(&p->config->print);
	printf("%ld Philo %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->config->print);
}

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
