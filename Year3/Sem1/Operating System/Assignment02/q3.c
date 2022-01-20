#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
I have used 5 producers and 5 consumers to demonstrate the solution. You can always play with these values.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer
//To declare a semaphore, the data type is sem_t.
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand()%10; // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);//decrement of sema value
        pthread_mutex_lock(&mutex);//To lock a semaphore or wait we can use the sem_wait function
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);//To release or signal a semaphore, we use the sem_post function,increment 
    }
}

int main()
{   

    pthread_t pro[20],con[20];//thread variable to identify thread in the system
    int n_prod, n_con;
    pthread_mutex_init(&mutex, NULL);
    //A semaphore is initialised by using sem_init(for processes or threads)
    // or sem_open (for IPC).
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    printf("Enter No. of Producers : ");
    scanf("%d",&n_prod);
    printf("Enter No. of Consumers : ");
    scanf("%d",&n_con);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer
    int *prod_arr = (int*)malloc(n_prod*sizeof(int));
    int *con_arr = (int*)malloc(n_con*sizeof(int));
    for(int i = 0; i < n_prod; i++) {
        prod_arr[i]=i+1;
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&prod_arr[i]);
        //pthread_create() function to create a thread
        //The first argument is a pointer to thread_id which is set by this function.
        //The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
        //The third argument is name of function to be executed for the thread to be created.
        //The fourth argument is used to pass arguments to the function, myThreadFun.
    }
    for(int i = 0; i < n_con; i++) {
        con_arr[i]=i+1;
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&con_arr[i]);
    }

    for(int i = 0; i < n_prod; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < n_con; i++) {
        pthread_join(con[i], NULL);
        //The pthread_join() function for threads is the equivalent of wait() for processes.
        // A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);//To destroy a semaphore, we can use sem_destroy.
    sem_destroy(&full);

    return 0;
    
}

//    sem : Specifies the semaphore to be initialized.
//  pshared : This argument specifies whether or not the newly initialized semaphore is shared between processes or between threads.
// A non-zero value means the semaphore is shared between processes and a value of zero means it is shared between threads.
//  value : Specifies the value to assign to the newly initialized semaphore.



//Mutexes: Routines that deal with synchronization, called a "mutex", which is an abbreviation for "mutual exclusion".
// Mutex functions provide for creating, destroying, locking and unlocking mutexes.
// These are supplemented by mutex attribute functions that set or modify attributes associated with mutexes.

