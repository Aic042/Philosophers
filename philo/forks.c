#include "philo.h"

void print_status(t_philo *p, char *msg)
{
	long timestamp;
	timestamp = get_time_ms() - p->config->start_time;
	pthread_mutex_lock(&p->config->print);
	printf("%ld Philo %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->config->print);
}

// int is_dead(t_philo *p)
// {
	
// }