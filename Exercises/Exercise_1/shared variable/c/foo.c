// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>
pthread_mutex_t lock;

int i = 1;

// Note the return type: void*
void* incrementingThreadFunction(){
        pthread_mutex_lock(&lock);

    for (int b = 0; b < 1000000; b++)
    {
    i++;
    if (b%100000==0)
    {
    printf("The magic number is: %d\n", i);
    }
    }
        pthread_mutex_unlock(&lock);

    return NULL;
}

void* decrementingThreadFunction(){
        pthread_mutex_lock(&lock);

    for (int c = 0; c < 1000000; c++)
    {
    i--;
    if (c%100000==0)
    {
    printf("The magic number is: %d\n", i);
    }
    }
        pthread_mutex_unlock(&lock);

    return NULL;
}


int main(){
    pthread_t thread0, thread1;
    // Creating the first thread
    if (pthread_create(&thread0, NULL, incrementingThreadFunction, NULL)) {
        printf("Error creating thread 1\n");
        return 1;
    }

    // Creating the second thread
    if (pthread_create(&thread1, NULL, decrementingThreadFunction, NULL)) {
        printf("Error creating thread 2\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    
    printf("The final magic number is: %d\n", i);
    return 0;
}
