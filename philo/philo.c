/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:59:01 by root              #+#    #+#             */
/*   Updated: 2025/07/14 18:40:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleaner(t_config *c, t_philo *p, pthread_t  *threads)
{
	if(c)
		free(c);
	if (p)
		free(p);
	if (threads)
		free (threads);
}

void init_structs(t_philo *philos, t_config *config)
{
    int i;

    for (i = 0; i < config->philo_num; i++)
    {
        philos[i].id = i + 1;
        philos[i].config = config;
        philos[i].times_ate = 0;
        philos[i].unalived = 0;
        philos[i].left_fork_id = i;
        philos[i].right_fork_id = (i + 1) % config->philo_num;
        philos[i].last_meal_time = config->start_time;
        pthread_mutex_init(&philos[i].death_mutex, NULL);
    }
}


int main(int argc, char **argv)
{
	if (!arg_checker(argc, argv))
		return (1);
	int i;
	i = 0;
	int n;
	n = ft_atoi(argv[1]);
	t_philo *philos = malloc(sizeof(t_philo) * n);
	pthread_t *threads = malloc(sizeof(pthread_t) * n);
	memset(philos, 0, sizeof(t_philo) * n);
	t_config *config = malloc(sizeof(t_config));
	initialize_var(argv, config);
	config->forks = malloc(sizeof(t_fork) * config->philo_num);
	for (int i = 0; i < config->philo_num; i++)
		pthread_mutex_init(&config->forks[i].fork, NULL);
	
	if (!philos || !threads || !config)
		printf("Error, structs malloc");
	init_structs(philos, config);
	for (i = 0; i < n; i++)
			pthread_create(&threads[i], NULL, routine, &philos[i]);
	for (i = 0; i < n; i++)
	{
			pthread_mutex_init(&philos[i].death_mutex, NULL);
			philos[i].unalived = 0;
			philos[i].left_fork_id  = i;
			philos[i].right_fork_id = (i + 1) % n;
			philos[i].last_meal_time = config->start_time;
	}

	for (i = 0; i < n; i++)
		pthread_join(threads[i], NULL);
	printf("times eaten: %d\n", philos->times_ate);
	// free(philos);
	// free(threads);
	// free(config);
	cleaner(config, philos, threads);
	return 0;
}
