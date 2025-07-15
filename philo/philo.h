/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:39 by root              #+#    #+#             */
/*   Updated: 2025/07/15 12:30:50 by aingunza         ###   ########.fr       */
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
# include <limits.h>

# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define IS_FORK "has taken a fork"
# define IS_DEAD "died"

typedef struct s_fork
{
	long			id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_config
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_fork			*forks;
	long			start_time;
	int				exit;
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	pthread_mutex_t	take_forks;
}	t_config;

typedef struct s_philo
{
	pthread_mutex_t	death_mutex;
	int				left_fork_id;
	int				right_fork_id;
	int				id;
	int				is_sleeping;
	int				is_eating;
	int				is_thinking;
	long			last_meal_time;
	int				times_ate;
	int				unalived;
	t_config		*config;
	t_fork			*fork;
}	t_philo;

////////////////// PARSING //////////////////////
int		arg_checker(int argc, char **argv);

/////////////// MISCELLANEOUS //////////////
void	initialize_threads(char **argv);
void	eepy_philo(t_philo *p);
void	philo_feeder(t_philo *p);
void	philo_think(t_philo *p);
void	*routine(void *arg);
long	get_time_ms(void);
void	initialize_variables(t_philo *p, char **argv);
void	print_status(t_philo *p, char *msg);
void	initialize_var(char **argv, t_config *c);
void	var_cleaner(t_config *c);
int		ft_atoi(const char *str);
int		is_str_digit(char *str);
void	cleaner(t_config *c, t_philo *p, pthread_t *threads);
int		die_checker(t_philo *p);
void	*monitor(void *arg);
void	philo_die(t_philo *p);
#endif