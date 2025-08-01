/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:44:54 by root              #+#    #+#             */
/*   Updated: 2025/07/30 12:17:09 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_structs(t_philo *philos, t_config *config)
{
	int	i;

	mutex_initializer(config);
	config->forks = (t_fork *)malloc(sizeof(t_fork) * config->philo_num);
	if (!config->forks)
		return ;
	config->exit = 0;
	i = -1;
	while (++i < config->philo_num)
	{
		config->forks[i].id = i;
		pthread_mutex_init(&config->forks[i].fork, NULL);
	}
	i = -1;
	while (++i < config->philo_num)
	{
		philos[i].id = i + 1;
		philos[i].config = config;
		philos[i].times_ate = 0;
		philos[i].is_thinking = 1;
	}
	pthread_mutex_init(&config->last_meal_mutex, NULL);
}

void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	diners;

	diners = philo->config->philo_num;
	philo->fork_r = &forks[(pos + 1) % diners];
	philo->fork_l = &forks[pos];
	if (philo->id % 2)
	{
		philo->fork_r = &forks[pos];
		philo->fork_l = &forks[(pos + 1) % diners];
	}
}

void	init_variables(int argc, char **argv, t_philo *p, t_config *config)
{
	int	pos;

	pos = 0;
	while (pos < p->config->philo_num)
	{
		p[pos].id = pos + 1;
		p[pos].is_sleeping = 0;
		p[pos].is_eating = 0;
		p[pos].is_thinking = 1;
		p[pos].times_ate = 0;
		p[pos].unalived = 1;
		p[pos].last_meal_time = p->config->start_time;
		assign_forks(&p[pos], p->config->forks, pos);
		pos++;
	}
	config->time_to_die = ft_atol(argv[2]);
	config->time_to_eat = ft_atol(argv[3]);
	config->time_to_sleep = ft_atol(argv[4]);
	check_times_philo_eats(argc, argv, config);
}

void	cleaner(t_philo *p, t_config *config)
{
	int	i;

	i = 0;
	while (i < config->philo_num)
		pthread_mutex_destroy(&config->forks[i++].fork);
	pthread_mutex_destroy(&config->death_mutex);
	pthread_mutex_destroy(&config->print);
	pthread_mutex_destroy(&config->meals);
	pthread_mutex_destroy(&config->take_forks);
	pthread_mutex_destroy(&config->exit_mutex);
	free(config->forks);
	free(config);
	free(p);
}

int	main(int argc, char **argv)
{
	t_config	*config;
	t_philo		*p;

	if (argc != 5 && argc != 6)
		return (printf("Bad Argc\n"), 1);
	config = malloc(sizeof(t_config));
	if (!config)
		return (1);
	config->philo_num = ft_atol(argv[1]);
	p = malloc(sizeof(t_philo) * config->philo_num);
	if (!p)
		return (1);
	if (arg_checker(argc, argv) == 0)
	{
		free(config);
		free(p);
		return (1);
	}
	config->start_time = get_time_ms();
	init_structs(p, config);
	init_variables(argc, argv, p, config);
	meal(p);
	cleaner(p, config);
	return (0);
}
