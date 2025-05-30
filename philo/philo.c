/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
/*   Updated: 2025/05/19 12:49:19 by aingunza         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	forks;

	if (!arg_checker(argc, argv))
		exit(1);
	initialize_threads(argv);
	forks = fork_getter(argv);
	ft_printf("forks = %d\n", forks);
	return (write(1, "Done\n", 5), 0);
}

//for later, should check if it's better to have an int