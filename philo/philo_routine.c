#include "philo.h"

void eepy_philo(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is sleeping\n", timestamp, p->id);
	usleep(p->config->time_to_sleep * 1000);
}

void philo_feeder(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is eating\n", timestamp, p->id);
	usleep(p->config->time_to_eat * 1000);
}

void philo_die(t_philo *p)
{
	
	long timestamp = get_time_ms() - p->config->start_time;
	if (p->to_die >= p->config->time_to_die)
		printf("%ld | philo %d died", timestamp, p->id);
}

void philo_think(t_philo *p)
{
	long timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d is thinking\n", timestamp, p->id);
	usleep(p->config->time_to_eat * 1000);
}



void *routine(void *arg)
{
	t_philo *p = (t_philo *)arg;

	while (1)
	{
		eepy_philo(p);
		philo_feeder(p);
		philo_think(p);
	}
	return NULL;
}

// void philo_philosophize(t_philo *p, timestamp, t_config *c)
// {
// 	printf("time: %ld | Philo %d is thinkinh", timestamp, p->id);
// 	usleep(c->think);
// }