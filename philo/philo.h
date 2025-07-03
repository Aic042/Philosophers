/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:39 by root              #+#    #+#             */
/*   Updated: 2025/07/01 13:35:35 by root             ###   ########.fr       */
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


typedef struct s_fork
{
	long 			id;
	pthread_mutex_t	fork;
	// t_philo 		*phil;
} t_fork;

typedef struct s_config
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				last_meal;
	t_fork			*r_fork;
	t_fork			*l_fork;
	pthread_t		main_thread;
	long			start_time;
}	t_config;

typedef struct s_philo
{
	pthread_mutex_t	death;
	pthread_mutex_t	print;
	int 			id;
	int				to_eat;
	int				to_sleep;
	int				to_die;
	int				times_ate;
	int				unalived;
	t_config		*config;
	t_fork			*fork;
} t_philo;

// typedef struct s_misc
// {
// } t_misc;
////////////////// PARSING //////////////////////
int		arg_checker(int argc, char **argv);

/////////////// MISCELLANEOUS //////////////
void	initialize_threads(char **argv);
void	eepy_philo(t_philo *p);
void	philo_feeder(t_philo *p);
void	philo_think(t_philo *p);
void	 *routine(void *arg);
long	get_time_ms(void);

#endif