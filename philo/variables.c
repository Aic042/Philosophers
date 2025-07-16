/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:25 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/16 08:26:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    initialize_var(char **argv, t_config *c)
{
	c->philo_num = ft_atoi(argv[1]);
	c->time_to_die = ft_atoi(argv[2]);
	c->time_to_eat = ft_atoi(argv[3]);
	c->time_to_sleep = ft_atoi(argv[4]);
	c->exit = 0;
	c->start_time = get_time_ms();
	pthread_mutex_init(&c->print, NULL);
	pthread_mutex_init(&c->meals, NULL);
	pthread_mutex_init(&c->take_forks, NULL);
	pthread_mutex_init(&c->exit_mutex, NULL);
	if (argv[5])
		c->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		c->number_of_times_each_philosopher_must_eat = -1;  // No hay límite
}
void set_exit(t_config *c, int value)
{
    pthread_mutex_lock(&c->exit_mutex);
    c->exit = value;
    pthread_mutex_unlock(&c->exit_mutex);
}

int get_exit(t_config *c)
{
    int value;
    pthread_mutex_lock(&c->exit_mutex);
    value = c->exit;
    pthread_mutex_unlock(&c->exit_mutex);
    return value;
}
