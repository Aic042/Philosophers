/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:59:01 by root              #+#    #+#             */
/*   Updated: 2025/07/16 08:02:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleaner(t_config *c, t_philo *p, pthread_t *threads)
{
    if (c)
    {
        if (c->forks)
            free(c->forks);
        free(c);
    }
    if (p)
        free(p);
    if (threads)
        free(threads);
}




void	init_structs(t_philo *philos, t_config *config)
{
	int	i;

	i = 0;
	while (i < config->philo_num)
	{
		philos[i].id = i + 1;
		philos[i].config = config;
		philos[i].times_ate = 0;
		philos[i].unalived = 0;
		philos[i].left_fork_id = i;
		philos[i].right_fork_id = (i + 1) % config->philo_num;
		philos[i].last_meal_time = config->start_time;
		pthread_mutex_init(&philos[i].death_mutex, NULL);
		i++;
	}
}

void	fork_assigner(t_philo *p)
{
	p->left_fork_id = p->id - 1;
	if (p->id == p->config->philo_num)
		p->right_fork_id = 0;
	else
		p->right_fork_id = p->id;
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	if (!arg_checker(argc, argv))
		return (1);
	i = 0;
	n = ft_atoi(argv[1]);
	t_philo *philos = malloc(sizeof(t_philo) * n);
	pthread_t *threads = malloc(sizeof(pthread_t) * n);
	memset(philos, 0, sizeof(t_philo) * n);
	t_config *config = malloc(sizeof(t_config));

	initialize_var(argv, config);
	config->forks = malloc(sizeof(t_fork) * config->philo_num);
	pthread_t monitor_thread;
	
	for (int i = 0; i < config->philo_num; i++)
		pthread_mutex_init(&config->forks[i].fork, NULL);
	if (!philos || !threads || !config)
		printf("Error, structs malloc");
	init_structs(philos, config);
	if (n == 1)
	{
		check_one_philo(&philos[0]);
		cleaner(config, philos, threads);
		return (0);
	}
	for (i = 0; i < n; i++)
		pthread_create(&threads[i], NULL, routine, &philos[i]);
	pthread_create(&monitor_thread, NULL, monitor, philos);
	for (i = 0; i < n; i++)
		pthread_join(threads[i], NULL);
	// printf("times eaten: %d\n", philos->times_ate);
	pthread_join(monitor_thread, NULL);
	cleaner(config, philos, threads);
	return 0;
}
