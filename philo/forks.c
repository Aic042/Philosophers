#include "philo.h"

void print_status(t_philo *p, char *msg)
{
	long timestamp;

	pthread_mutex_lock(&p->config->print);
	timestamp = get_time_ms() - p->config->start_time;
	printf("%ld | Philo %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->config->print);
}