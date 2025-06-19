/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
/*   Updated: 2025/06/19 11:07:21 by aingunza         ###   ########.fr       */
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

double cur_time_getter(void)
{
	struct timeval time;
	double current;
	gettimeofday(&time, NULL);
	current = time.tv_sec + time.tv_usec / 1000000.0;
	return (current);
}


int	main(int argc, char **argv)
{
	int	forks;

	if (!arg_checker(argc, argv))
		exit(1);
	double start = cur_time_getter();
	// initialize_threads(argv);
	forks = fork_getter(argv);
	ft_printf("forks = %d\n", forks);
	printf("time is: %.3f\n", cur_time_getter() - start);
	usleep(100000); // 100ms
	printf("now time is: %.3f\n", cur_time_getter() - start);

	return (write(1, "Done\n", 5), 0);
}

//for later, should check if it's better to have an int