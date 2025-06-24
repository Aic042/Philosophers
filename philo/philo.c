/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
/*   Updated: 2025/06/24 14:52:29 by aingunza         ###   ########.fr       */
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

int cur_time_getter(void)
{
	struct timeval time;
	int current;
	gettimeofday(&time, NULL);
	current = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (current);
}

int	main(int argc, char **argv)
{
	int	forks;

	if (!arg_checker(argc, argv))
		exit(1);
	int start = cur_time_getter();
	// initialize_threads(argv);
	forks = fork_getter(argv);
	printf("forks = %d\n", forks);
	while (1)
	{
		printf("time is: %d\n", cur_time_getter() - start);
		usleep(12222); // 100ms
		printf("now time is: %d\n", cur_time_getter() - start);
	}
	return (write(1, "Done\n", 5), 0);
}

//for later, should check if it's better to have an int