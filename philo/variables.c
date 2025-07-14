/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:25 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/14 12:48:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void initialize_var(char **argv, t_config *c)
{
    c->philo_num = ft_atoi(argv[1]);
    c->time_to_die = ft_atoi(argv[2]);
    c->time_to_eat = ft_atoi(argv[3]);
    c->time_to_sleep = ft_atoi(argv[4]);
    c->exit = 0;
    // c->number_of_times_each_philosopher_must_eat = (argv[5] ? ft_atoi(argv[5]) : -1);
    c->start_time = get_time_ms();    
    pthread_mutex_init(&c->print, NULL);
}
