#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>

//I am solving with mutex lock since the time the variable is locked for is just one addition or subtraction, which takes one clock tic. 
//If I were to solve this using semaphores, the amount of processing work in the code would essentialy double. 
int i = 0;
pthread_mutex_t counter_mutex;

//The problem could be solved by introducing an atmoic variable. 
//atomic_int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
    pthread_mutex_lock(&counter_mutex);
    i++;
    pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
    pthread_mutex_lock(&counter_mutex);
    i--;
    pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
