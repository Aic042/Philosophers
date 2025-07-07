/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:59:01 by root              #+#    #+#             */
/*   Updated: 2025/07/07 14:00:56 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_getter(char **argv)
{
	int	forks;

	forks = ft_atoi(argv[1]);
	return (forks);
}
// forks = forks + 1;
// void variable_initializer()
// {
// 	struct timeval time;
// 	int current;
// 	gettimeofday(&time, NULL);
// 	current = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
// 	return (current);
// }

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
	if (!philos || !threads || !config)
		printf("Error, structs malloc");
	initialize_var(argv, config);
	for (i = 0; i < n; i++)
	{
		philos[i].id = i + 1;
		philos[i].config = config;
		philos[i].times_ate = 0;
		philos[i].last_meal_time = config->start_time;
    	pthread_create(&threads[i], NULL, routine, &philos[i]);
	}

	for (i = 0; i < n; i++)
		pthread_join(threads[i], NULL);
	printf("times eaten: %d\n", philos->times_ate);
	free(philos);
	free(threads);
	free(config);
	return 0;
}



// int	main(int argc, char **argv)
// {
// 	int	forks;

// 	if (!arg_checker(argc, argv))
// 		exit(1);
// 	forks = fork_getter(argv);
// 	printf("forks = %d\n", forks);
// 	pthread_t thread1;
// 	pthread_create(&thread1, NULL, routine, NULL);	
// 	return (write(1, "Done\n", 5), 0);
// }
	
// int start = cur_time_getter();
// while (1)
// {
// 	printf("time is: %d\n", cur_time_getter() - start);
// 	usleep(12222); // 100ms
// 	printf("now time is: %d\n", cur_time_getter() - start);
// }
//for later, should check if it's better to have an int