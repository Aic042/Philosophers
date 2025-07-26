/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:39 by root              #+#    #+#             */
/*   Updated: 2025/07/26 13:41:24 by root             ###   ########.fr       */
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
	int				num_of_times_each_philo_must_eat;
	t_fork			*forks;
	long			start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	pthread_mutex_t	take_forks;
	pthread_mutex_t	exit_mutex;
	int				exit;
	pthread_mutex_t	death_mutex;
}	t_config;

typedef struct s_philo
{
	int				left_fork_id;
	pthread_t		threads;
	int				right_fork_id;
	int				id;
	int				is_sleeping;
	int				is_eating;
	int				is_thinking;
	long			last_meal_time;
	int				times_ate;
	int				unalived;
	t_config		*config;
	t_fork			*fork_r;
	t_fork			*fork_l;
}	t_philo;

////////////////// PARSING //////////////////////
int		arg_checker(int argc, char **argv);

/////////////// UTILS ///////////////////////////
long	ft_atol(const char *str);
int		ft_isdigit(int c);
// int	 ft_isspace(int c);
int		is_str_digit(char *str);

/////////////// CORE UTILS //////////////////////
long	get_time_ms(void);
void	sleep_function(t_philo *p, int time);
int		die_checker(t_philo *p);
int		check_one_philo(t_philo *p);

/////////////// INITIALIZATION //////////////////
void	init_structs(t_philo *philos, t_config *config);
void	init_variables(int argc, char **argv, t_philo *p, t_config *config);
void	assign_forks(t_philo *philo, t_fork *forks, int pos);

/////////////// PHILOSOPHER ROUTINE /////////////
void	*routine(void *arg);
void	meal(t_philo *p);
void	*monitor_routine(void *arg);

/////////////// ACTIONS /////////////////////////
void	print_status(t_philo *p, char *msg);
void	philo_die(t_philo *p);
void	init_sleep(t_philo *p);
void	philo_think(t_philo *p);
void	eepy_philo(t_philo *p);
int		time_over(t_philo *p);
void	philo_eat(t_philo *p);
int		all_philos_ate_enough(t_philo *p);
void	joint_actions(t_philo *p);
/////////////// PLACEHOLDERS ////////////////////
int		get_exit(t_config *c);
void	set_exit(t_config *c, int value);
void	cleaner(t_philo *p, t_config *config);
void	philo_eat_helper(t_philo *p);
int		three_philos(t_philo *p);

#endif