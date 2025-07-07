/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:33:25 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/07 10:51:36 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void initialize_var(char **argv, t_config *c)
{
    c->philo_num = ft_atoi(argv[1]);
    c->time_to_die = ft_atoi(argv[2]);
    c->time_to_eat = ft_atoi(argv[3]);
    c->time_to_sleep = ft_atoi(argv[4]);
    c->number_of_times_each_philosopher_must_eat = (argv[5] ? ft_atoi(argv[5]) : -1);
    c->start_time = get_time_ms();
    c->r_fork = malloc(sizeof(t_fork) * c->philo_num);
    int i;
    i = 0;
    while (i < c->philo_num)
    {
        c->r_fork[i].id = 1; //why "." and not "->"
        pthread_mutex_init(&c->r_fork[i].fork, NULL);
        i++;
    }
    
    pthread_mutex_init(&c->print, NULL);
}

void var_cleaner(t_config *c)
{
    int i = 0;
    while (i < c->philo_num)
    {
        pthread_mutex_destroy(&c->r_fork[i].fork);
        i++;
    }
    free(c->r_fork);
}