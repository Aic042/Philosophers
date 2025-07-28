/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:51:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/28 16:33:20 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	time_over(t_philo *p)
{
	long	now;
	int		result;

	now = get_time_ms();
	pthread_mutex_lock(&p->config->death_mutex);
	pthread_mutex_lock(&p->config->last_meal_mutex);
	result = (now - p->last_meal_time > p->config->time_to_die);
	pthread_mutex_unlock(&p->config->last_meal_mutex);
	pthread_mutex_unlock(&p->config->death_mutex);
	return (result);
}
