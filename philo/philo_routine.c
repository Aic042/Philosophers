#include "philo.h"

void eepy_philo(t_philo *p, t_config *c)
{
	printf("Philo %d is sleeping", p->id);
	usleep(c->time_to_sleep);
}

void philo_feeder(t_philo *p, t_config *c)
{
	printf("Philo %d is eating", p->id);
	usleep(c->time_to_eat);
}

void philo_philosophize(t_philo *p, t_config *c)
{
	printf("Philo %d is thinkinh", p->id);
	usleep(c->think);
}