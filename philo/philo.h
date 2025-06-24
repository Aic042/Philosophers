/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:39 by root              #+#    #+#             */
/*   Updated: 2025/06/24 15:19:53 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>  // To use pthread_create, pthread_detach, pthread_join
# include <stdio.h>    // To use printf
# include <stdlib.h>   // To use malloc, free
# include <string.h>   // To use memset
# include <sys/time.h> // To use gettimeofday
# include <unistd.h>   // To use write, usleep
# include "../libft/libft.h"

# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define IS_FORK "has taken a fork"
# define IS_DEAD "died"

typedef struct s_config
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_config;

typedef struct s_philo
{
	int id;
} t_philo;

typedef struct s_fork
{
	int id;
	int is_taken;
} t_fork;
// typedef struct s_misc
// {
// } t_misc;
////////////////// PARSING //////////////////////
int		arg_checker(int argc, char **argv);

/////////////// MISCELLANEOUS //////////////
void	initialize_threads(char **argv);
void	eepy_philo(t_philo *p);
void	philo_feeder(t_philo *p);
void	philo_philosophize(t_philo *p);

#endif