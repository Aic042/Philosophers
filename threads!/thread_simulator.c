// #include "../philo/philo.h"



// int main(void)
// {
// 	pthread_t thread[5];
// 	int i;
// 	PTHREAD_CREATE_JOINABLE
// 	while (thread[i] < thread[5])
// 	{
// 		printf("id of p_thread is %ld\n", thread[i]);
// 		i++;
// 	}
// 	return(write(1, "done\n", 5), 0);
// }

#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // For sleep

#define NUM_THREADS 5

// Thread function that each thread will execute
void *thread_function(void *arg) {
    // Get the thread index from the argument
    int thread_id = *(int *)arg;
    printf("Thread %d: My pthread ID is %lu\n", thread_id, pthread_self());
    sleep(1); // Sleep for 1 second
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS]; // Store thread indices
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; // Pass thread index as argument
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }
        printf("Main: Created thread %d\n", i);
    }

    // Join threads (wait for them to finish)
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return 1;
        }
        printf("Main: Joined thread %d\n", i);
    }

    printf("done\n");
    return 0;
}