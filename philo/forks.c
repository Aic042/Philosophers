/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:41:21 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/16 08:34:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_status(t_philo *p, char *msg)
{
    long timestamp;

    if (get_exit(p->config))
        return;

    pthread_mutex_lock(&p->config->print);
    timestamp = get_time_ms() - p->config->start_time;

    // Asegura que no se imprima después de que haya muerto alguien.
    if (!get_exit(p->config))
        printf("%ld %d %s\n", timestamp, p->id, msg);

    pthread_mutex_unlock(&p->config->print);
}


void	init_sleep(t_philo *p)
{
	if (p->id % 2 == 0)
		usleep(300);
	else if (p->config->philo_num % 2 != 0)
		usleep(450);
}

// printf("%ld Philo %d %s\n", timestamp, p->id, msg);