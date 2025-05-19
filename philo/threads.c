/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:37:18 by aingunza          #+#    #+#             */
/*   Updated: 2025/05/19 12:45:49 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_function(void *arg)
{
	ft_printf("Thread %d started\n", *(int *)arg);
	return (NULL);
}

void	initialize_threads(char **argv)
{
	int			i;
	int			num_threads;
	pthread_t	*threads;
	int			*ids;

	i = 0;
	num_threads = ft_atoi(argv[1]);
	threads = malloc(sizeof(pthread_t) * num_threads);
	ids = malloc(sizeof(int) * num_threads);
	if (!ids || !threads)
		return ;
	while (i++ != num_threads)
	{
		ids[i] = i;
		if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0)
			ft_printf("Thread creation failed, send help to threads.c");
	}
	i = 0;
	while (i < num_threads)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	free(ids);
}
//When philospher eats, he then wait for 2 conditions. 
//First he must have waited 200 ms and then a fork must be available.
//For the 
