#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

void *process1(void *arg)
{
    printf("Process 1 ON\n");
    return NULL;
}

void *process2(void *arg)
{
    printf("Process 2 ON\n");
    return NULL;
}

long time_diff(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

int main(void)
{
    pthread_t t1, t2;
    struct timeval start1, end1, start2, end2;

    gettimeofday(&start1, NULL);
    pthread_create(&t1, NULL, process1, NULL);
    pthread_join(t1, NULL);
    gettimeofday(&end1, NULL);

    gettimeofday(&start2, NULL);
    pthread_create(&t2, NULL, process2, NULL);
    pthread_join(t2, NULL);
    gettimeofday(&end2, NULL);

    long diff1 = time_diff(start1, end1);
    long diff2 = time_diff(start2, end2);

    printf("Time between start and end of Process 1: %ld microseconds\n", diff1);
    printf("Time between start and end of Process 2: %ld microseconds\n", diff2);

    return 0;
}
