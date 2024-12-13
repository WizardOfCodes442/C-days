#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    /* This funcrion prints the thread identifier and then exits*/
    printf("Hello World. Greeting from thread %d\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    /* The main program creates ten threads and exit*/
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++){
        printf("Main here. Creating Thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void*) i);

        if (status != 0){
            printf("oops. pthread_create returned error code %d\n", status);
            exit(-1);
        }
    }
    exit(NULL)
}