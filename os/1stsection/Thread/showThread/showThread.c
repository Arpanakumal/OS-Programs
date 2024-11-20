#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define NO_OF_THREADS 5
void *print_hello_world(void *tid)
{
    // This function prints thread's identifier and then exits
    printf("HelloWorldfromthread%d\n\n", *((int *)tid));
    // casting void pointer
    pthread_exit(NULL);
}
int main()
{
    // The main program creates5 threads
    pthread_t threads[NO_OF_THREADS];
    int status, i;
    for (i = 0; i < NO_OF_THREADS; i++)
    {
        printf("Mainhere.Creatingthread%d\n", i);
        status = pthread_create(&threads[i], NULL, &print_hello_world, &i);
    }
}
